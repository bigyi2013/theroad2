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
 bool  newyehoo(InputArray _charucoCorners, InputArray _charucoIds,
                              cv::Ptr <cv::aruco::CharucoBoard> _board, InputArray _cameraMatrix, InputArray _distCoeffs,  OutputArray _rvec, OutputArray _tvec, bool useExtrinsicGuess) {

    CV_Assert((_charucoCorners.getMat().total() == _charucoIds.getMat().total()));

    // need, at least, 4 corners
    if(_charucoIds.getMat().total() < 4) return false;

    vector< Point3f > objPoints;
    objPoints.reserve(_charucoIds.getMat().total());
    for(unsigned int i = 0; i < _charucoIds.getMat().total(); i++) {
        int currId = _charucoIds.getMat().at< int >(i);
        CV_Assert(currId >= 0 && currId < (int)_board->chessboardCorners.size());
        objPoints.push_back(_board->chessboardCorners[currId]);
    }


    return  true;
}
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
rvec2[0]=0;
rvec2[1]=0;
rvec2[2]=0;
tvec2[0]=0;
tvec2[1]=0;
tvec2[2]=0;
            break;

            case 1:
rvec2[0]=0;
rvec2[1]=0;
rvec2[2]=0;
tvec2[0]=0.84;
tvec2[1]=0;
tvec2[2]=0;
            break;

            case 2:
rvec2[0]=0;
rvec2[1]=-1.5708;
rvec2[2]=0;
tvec2[0]=1.955;
tvec2[1]=0.115;
tvec2[2]=0.565;
            break;

            case 3:
rvec2[0]=1;
rvec2[1]=2;
rvec2[2]=3;
tvec2[0]=1;
tvec2[1]=1;
tvec2[2]=1;
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
	//std::cout<<rvec2<<std::endl;
    cv::Rodrigues(rvec2, R2);
  //  std::cout << R2 << std::endl;
    T2 = DoubleMatFromVec3b(tvec2);
    pos = R2 * pos + T2;
 //   std::cout<<boardnum<<std::endl;
   //  std::cout<<pos.at<double>(1, 0)<<std::endl;

    return pos ;
}
int main() {
//   	cv ::Vec3d rtest(-0.0814333, 1.96827, -0.0326359);
//  cv ::Vec3d ttest(-0.0506093, -0.172714, 0.615068);
//   	cv ::Vec3d rtest1(0.0401312, -2.80887, -0.0390283);
//   cv ::Vec3d ttest1(0.18297, -0.164379, 0.578531);
//   	cv ::Vec3d rtest2;
//   cv ::Vec3d ttest2;
//   cv::Vec3d Rtest;
//  cv::composeRT(rtest,ttest,rtest1,ttest1,rtest2,ttest2);
//   cv::Mat xuexi = (cv::Mat_<double>(3, 3)
//             << 0, 0,-1, 0,1, 0, 0, 0, 0);
//  cv::Rodrigues(xuexi, Rtest);
//    cv::composeRT(rtest,ttest,rtest1,ttest1,rtest2,ttest2);
//    std::cout<<rtest2<<std::endl;
//     std::cout<<ttest2<<std::endl;
//   std::cout<<xuexi<<std::endl;
//     std::cout<<Rtest<<std::endl;

 int num = 0;
    cv::VideoCapture inputVideo;
    inputVideo.open(0);

    cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
            << 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
       8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
    cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -1.0666525029122846e-01, 3.3794337314215589e-01,
       1.6656304800872223e-05, -3.7943927324066247e-03,
       4.9543475405042214e-01);
    cv::Ptr <cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::Ptr <cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(3, 5, 0.055, 0.045, dictionary);
    //*******************************************
    viz::Color color=viz::Color::white();
    viz::Viz3d window("window");
    window.showWidget("Coordinate", viz::WCoordinateSystem());
    // cv::viz::WCameraPosition plane(cameraMatrix,scale,color);
    double scale=0.2;
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
        std::vector <std::vector<cv::Point2f > > corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);

        // if at least one marker detected
        if (ids.size() > 0) {
            std::vector <cv::Point2f> charucoCorners;
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
                                                                     distCoeffs, rvec, tvec);
			
					//valid=newyehoo(charucoCorners, charucoIds, board, cameraMatrix,   distCoeffs, rvec, tvec);
					std::cout<<charucoIds.size()<<std::endl;
                    // if charuco pose is valid
                    if (valid) {

                        //	std::cout<<"ids:"<<boardnum<<std::endl;
                        cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvec, tvec, 0.1);

						//判断ids(boardnum),r*pos+t
                        cv::Vec3d pos;
						pos=getrt( tvec, rvec,boardnum);
                        cv::Mat rmat;
                        Rodrigues(rvec, rmat);
                        Affine3d pose(rmat.inv(),pos);// Affine3f pose(r,t)
                       window.setWidgetPose("plane", pose);
                        plane.setPose(pose);
                     //   std::cout<<tvec(1)<<std::endl;
                        window.spinOnce(1, true);
                    //    std::cout<< charucoIds[0]<<std::endl;
                    }
                }
            }
        }
        cv::imshow("out", imageCopy);
        char key = (char) cv::waitKey(1);
        if (key == 27)
            break;
    }
}