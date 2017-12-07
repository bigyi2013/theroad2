//
// Created by yehoo on 17-12-7.
//

#include "main.h"

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
using namespace std;
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