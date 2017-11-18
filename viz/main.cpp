#include <opencv2/opencv.hpp>
#include <opencv2/viz/widgets.hpp>
#include <iostream>
#include <opencv2/viz.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
using namespace cv;
int main(){
    cv::Matx33d cameraMatrix = (8.6911353168659366e+02, 0, 2.9267783375673446e+02, 0,
            8.6721765725812759e+02, 2.9037435251520674e+02, 0, 0, 1);
double scale=2.0;
     viz::Color color=viz::Color::white();
    viz::Viz3d window("window");
    window.showWidget("Coordinate", viz::WCoordinateSystem());
   // cv::viz::WCameraPosition plane(cameraMatrix,scale,color);
    cv::viz::WCameraPosition plane(scale);
    //plane.setRenderingProperty(viz::LINE_WIDTH, 5);
   // std::vector T;

   // cv::viz::WTrajectory cpath(T,cv::viz::WTrajectory::PATH,scale,color);
    plane.setPose(Affine3f());
    window.showWidget("plane", plane);
   // window.spin();
    Mat rvec = Mat::zeros(1, 3, CV_32F);
    while(!window.wasStopped())
    {
        // interact with window
        rvec.at<float>(0,0) = 0.f;
        rvec.at<float>(0,2)=0.f;
        rvec.at<float>(0,2) += 3.141/2;
        rvec.at<float>(0,1) = 0.f;
        Mat rmat;

        Rodrigues(rvec, rmat);
        std::cout<<rmat<<std::endl;
        Affine3f pose(rmat, Vec3f(0,   rvec.at<float>(0,1),0));// Affine3f pose(r,t)
        window.setWidgetPose("plane", pose);
       // plane.setPose(pose);
        window.spinOnce(1, true);

    }

}