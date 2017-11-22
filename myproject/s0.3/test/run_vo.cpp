// -------------- test the visual odometry -------------
#include <fstream>
#include <boost/timer.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/viz.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include "myslam/config.h"
#include "myslam/visual_odometry.h"

int main(int argc, char **argv) {

   myslam::Config::setParameterFile(argv[1]);

    myslam::VisualOdometry::Ptr vo(new myslam::VisualOdometry);
    myslam::Camera::Ptr camera(new myslam::Camera);

    // visualization
    cv::viz::Viz3d vis("Visual Odometry");
    cv::viz::WCoordinateSystem world_coor(1.0), camera_coor(0.5);
    cv::Point3d cam_pos(0, -1.0, -1.0), cam_focal_point(0, 0, 0), cam_y_dir(0, 1, 0);
    cv::Affine3d cam_pose = cv::viz::makeCameraPose(cam_pos, cam_focal_point, cam_y_dir);
    vis.setViewerPose(cam_pose);

    world_coor.setRenderingProperty(cv::viz::LINE_WIDTH, 2.0);
    camera_coor.setRenderingProperty(cv::viz::LINE_WIDTH, 1.0);
    vis.showWidget("World", world_coor);
    vis.showWidget("Camera", camera_coor);

    cv::VideoCapture inputVideo;
    inputVideo.open(0);

    if (!inputVideo.isOpened()) {
        cout << "video open 不了，我回乱说？" << endl;
        return 1;
    }

    while (inputVideo.grab()) {
        cv::Mat image;
        inputVideo.retrieve(image);
        myslam::Frame::Ptr pFrame = myslam::Frame::createFrame();
        pFrame->camera_ = camera;
        pFrame->color_ = image;
        vo->findcharuco(pFrame);

        vo->myaddframe(pFrame);
        //SE3 Tcw = pFrame->T_c_w_.inverse();
        // show the map and the camera pose 
//        cv::Affine3d M(
//                cv::Affine3d::Mat3(
//                        Tcw.rotation_matrix()(0, 0), Tcw.rotation_matrix()(0, 1), Tcw.rotation_matrix()(0, 2),
//                        Tcw.rotation_matrix()(1, 0), Tcw.rotation_matrix()(1, 1), Tcw.rotation_matrix()(1, 2),
//                        Tcw.rotation_matrix()(2, 0), Tcw.rotation_matrix()(2, 1), Tcw.rotation_matrix()(2, 2)
//                ),
//                cv::Affine3d::Vec3(
//                        Tcw.translation()(0, 0), Tcw.translation()(1, 0), Tcw.translation()(2, 0)
//                )
//        );
        cv::Mat rmat,pos;
        std::cout<<pFrame->tvec_<<std::endl;
        cv::Rodrigues(pFrame->rvec_,rmat);
        pos=-rmat.inv()*pFrame->tvec_;
        cv::Affine3d pose(rmat.inv(), pos);
        cv::imshow("image", image);
        cv::waitKey(1);
        vis.setWidgetPose("Camera", pose);
       vis.spinOnce(1, false);
    }

    return 0;
}
