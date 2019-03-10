@@ -0,0 +1,209 @@
#include <opencv2/opencv.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <boost/timer.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/viz.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include "opencv2/aruco/charuco.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

cv::Mat DoubleMatFromVec3b(cv::Vec3d in) {
    cv::Mat mat(3, 1, CV_64FC1);
    mat.at<double>(0, 0) = in[0];
    mat.at<double>(1, 0) = in[1];
    mat.at<double>(2, 0) = in[2];
    return mat;
}

cv::Mat getrt(cv::Vec3d tvec, cv::Vec3d rvec, int boardnum) {
    cv::Vec3d tvec2;
    cv::Vec3d rvec2;
    switch (boardnum) {
        case 0:
            rvec2[0] = 0;
            rvec2[1] = 0;
            rvec2[2] = 0;
            tvec2[0] = 0;
            tvec2[1] = 0;
            tvec2[2] = 0;
            break;
        case 1:
            rvec2[0] = 0;
            rvec2[1] = 0;
            rvec2[2] = 0;
            tvec2[0] = 0.84;
            tvec2[1] = 0;
            tvec2[2] = 0;
            break;
        case 2:
            rvec2[0] = 0;
            rvec2[1] = -1.5708;
            rvec2[2] = 0;
            tvec2[0] = 1.955;
            tvec2[1] = 0.115;
            tvec2[2] = 0.565;
            break;
        case 3:
            rvec2[0] = 1;
            rvec2[1] = 2;
            rvec2[2] = 3;
            tvec2[0] = 1;
            tvec2[1] = 1;
            tvec2[2] = 1;
            break;
    }
    cv::Mat R;
    cv::Mat R_1;
    cv::Mat T;
    cv::Rodrigues(rvec, R);
    T = DoubleMatFromVec3b(tvec);
    R_1 = R.inv();
    cv::Mat pos;
    pos = R_1 * (-T);
    cv::Mat T2;
    cv::Mat R2;
    cv::Rodrigues(rvec2, R2);
    T2 = DoubleMatFromVec3b(tvec2);

    pos = R2 * pos + T2;
    return pos;
}

void mykalman2chushihua(KalmanFilter KF, double x, double dx) {

    randn(KF.statePost, Scalar::all(0), Scalar::all(0.1));
    KF.statePost = (Mat_<double>(2, 1) << x, dx);
}

int main() {
    cv::Mat colorImage(800, 800, CV_8UC3);
    //**********************
    KalmanFilter KF(6, 3, 0);
    Mat state(6, 1, CV_32F); /* (phi, delta_phi) */
    Mat processNoise(6, 1, CV_32F);
    Mat measurement = Mat::zeros(3, 1, CV_32F);
   // randn(state, Scalar::all(0), Scalar::all(0.1));//随机生成一个矩阵，期望是0，标准差为0.1;
    KF.transitionMatrix = (Mat_<float>(6, 6) << 1, 0, 0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1);//元素导入矩阵，按行;
    //!< measurement matrix (H) 观测模型
    setIdentity(KF.measurementMatrix);
    //!< process noise covariance matrix (Q)
    // wk 是过程噪声，并假定其符合均值为零，协方差矩阵为Qk(Q)的多元正态分布;
    setIdentity(KF.processNoiseCov, Scalar::all(0.00001));
    //!< measurement noise covariance matrix (R)
    //vk 是观测噪声，其均值为零，协方差矩阵为Rk,且服从正态分布;
    setIdentity(KF.measurementNoiseCov, Scalar::all(0.3));
    //!< priori error estimate covariance matrix (P'(k)): P'(k)=A*P(k-1)*At + Q)*/  A代表F: transitionMatrix
    //预测估计协方差矩阵;
    setIdentity(KF.errorCovPost, Scalar::all(1));
    //!< corrected state (x(k)): x(k)=x'(k)+K(k)*(z(k)-H*x'(k))
    randn(KF.statePost, Scalar::all(0), Scalar::all(0.1));
    //***************************
    int num = 0;
    cv::VideoCapture inputVideo;
    inputVideo.open(0);
    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
            << 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
            8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
    cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -1.0666525029122846e-01, 3.3794337314215589e-01,
            1.6656304800872223e-05, -3.7943927324066247e-03,
            4.9543475405042214e-01);
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(3, 5, 0.055, 0.045, dictionary);
    //*******************************************
    viz::Color color = viz::Color::white();
    viz::Viz3d window("window");
    window.showWidget("Coordinate", viz::WCoordinateSystem());
    // cv::viz::WCameraPosition plane(cameraMatrix,scale,color);
    double scale = 0.2;
    cv::viz::WCameraPosition plane(scale);
    //plane.setRenderingProperty(viz::LINE_WIDTH, 5);
    plane.setPose(Affine3f());
    window.showWidget("plane", plane);
    // window.spin();
    //*******************************************
    Mat rvec = Mat::zeros(1, 3, CV_32F);
    while (inputVideo.grab()) {
        cv::Mat image, imageCopy;
        inputVideo.retrieve(image);
        image.copyTo(imageCopy);
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);
        // if at least one marker detected
        if (ids.size() > 0) {
            std::vector<cv::Point2f> charucoCorners;
            std::vector<int> charucoIds;
            int boardnum;
            int i;
            for (boardnum = 0; boardnum < 3; boardnum++) {
                for (i = 0; i < 7; i++) {
                    board->ids.erase(board->ids.begin());
                    board->ids.push_back(i + 7 * boardnum);
                }
                cv::aruco::interpolateCornersCharuco(corners, ids, image, board, charucoCorners, charucoIds,
                                                     cameraMatrix, distCoeffs);
                if (charucoIds.size() > 0) {
                    cv::aruco::drawDetectedCornersCharuco(imageCopy, charucoCorners, charucoIds, cv::Scalar(255, 0, 0));
                    cv::Vec3d rvec, tvec;
                    //charucoCorners 就是imgcorner;角点在图像上的坐标.
                    bool valid = cv::aruco::estimatePoseCharucoBoard(charucoCorners, charucoIds, board, cameraMatrix,
                                                                     distCoeffs, rvec, tvec, false);
                    //     std::cout << "rvec:" << rvec << std::endl;
                    // if charuco pose is valid
                    if (valid) {
                        cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvec, tvec, 0.1);
                        //判断ids(boardnum),r*pos+t
                        cv::Vec3d pos;
                        pos = getrt(tvec, rvec, boardnum);
                        Mat prediction = KF.predict();
                        float x,y,z;
                        x=prediction.at<float>(0,0);
                        y=prediction.at<float>(1,0);
                        z=prediction.at<float>(2,0);
                        measurement.at<float>(0,0)=(float)pos[0];
                        measurement.at<float>(1,0)=(float)pos[1];
                        measurement.at<float>(2,0)=(float)pos[2];
                        KF.correct(measurement);
                        //***************************************
                       // pos2 = pos;
                        //对rvec2和tvec进行”卡而慢“滤波。
                        //或者多pos进行卡而慢
                        // cv::Mat rmat;
                        // std::cout<<rvec<<std::endl;
                        //  Rodrigues(rvec, rmat);
                        //  Affine3d pose(rmat.inv(), pos);// Affine3f pose(r,t)
                        //  window.setWidgetPose("plane", pose);
                        //  plane.setPose(pose);
                        //  window.spinOnce(1, true);
                       // std::cout<<"x:" <<x <<"******x2:"<<pos[0]<< std::endl;
                       // std::cout<<"y:" <<y<<"******x2:"<<pos[1]<< std::endl;
                        cv::Point m_position;
                        m_position.x=(int)((-x+1)*300);
                        m_position.y=(int)((y+1)*300);
                        std::cout<<"y:" <<y<<"******x2:"<<pos[1]<< std::endl;
                        cv::circle(colorImage,m_position, 0, CV_RGB(0, 255, 0), 3);
                        //std::cout<<"z:" <<z <<"******x2:"<<pos[2]<< std::endl;
                    }
                }
            }
        }
        cv::imshow("out", imageCopy);
        cv::imshow("point", colorImage);
        char key = (char) cv::waitKey(1);
        if (key == 27)
            break;
    }
}


