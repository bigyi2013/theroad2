//
// Created by yehoo on 17-12-7.
//

#include "main.h"

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include "ceres/ceres.h"
#include "rotation.h"
using namespace std;
class SnavelyReprojectionError
{
public:
    SnavelyReprojectionError(double observation_x, double observation_y):observed_x(observation_x),observed_y(observation_y){}

    template<typename T>
    bool operator()(const T* const camera,
                    const T* const point,
                    T* residuals)const{
        // camera[0,1,2] are the angle-axis rotation.
        T p[3];
        AngleAxisRotatePoint(camera, point, p);
        // camera[3,4,5] are the translation.
        p[0] += camera[3]; p[1] += camera[4]; p[2] += camera[5];

        // Compute the center of distortion. The sign change comes from
        // the camera model that Noah Snavely's Bundler assumes, whereby
        // the camera coordinate system has a negative z axis.
        T xp = - p[0] / p[2];
        T yp = - p[1] / p[2];

        // Apply second and fourth order radial distortion.
        const T& l1 = camera[7];
        const T& l2 = camera[8];
        T r2 = xp*xp + yp*yp;
        T distortion = T(1.0) + r2  * (l1 + l2  * r2);

        // Compute final projected point position.
        const T& focal = camera[6];
        T predicted_x = focal * distortion * xp;
        T predicted_y = focal * distortion * yp;

        // The error is the difference between the predicted and observed position.
        residuals[0] = predicted_x - T(observed_x);
        residuals[1] = predicted_y - T(observed_y);

        return true;
    }

    static ceres::CostFunction* Create(const double observed_x, const double observed_y){
        return (new ceres::AutoDiffCostFunction<SnavelyReprojectionError,2,9,3>(
                new SnavelyReprojectionError(observed_x,observed_y)));
    }


private:
    double observed_x;
    double observed_y;
};

int main(){
    cv::VideoCapture inputVideo;
    inputVideo.open(0);
    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 876.54585602, 0, 353.21887271, 0, 876.30286197, 198.42897486, 0, 0, 1);
    cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -0.11425339, 1.38441799, 0.0079628, 0.01205705, -3.59133568);
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    //cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    while (inputVideo.grab()) {
        cv::Mat image, imageCopy;
        inputVideo.retrieve(image);
        image.copyTo(imageCopy);
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f > > corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);
        // if at least one marker detected
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
            vector< cv::Mat > rvecs, tvecs;
            cv::aruco::estimatePoseSingleMarkers(corners, 0.2, cameraMatrix, distCoeffs, rvecs, tvecs);
            // draw axis for each marker
            for (int i = 0; i < ids.size(); i++){
                cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);

            }
        }

        cv::imshow("out", imageCopy);

        char key = (char)cv::waitKey(1);
        if (key == 27)
            break;
    }
    return 0;
}