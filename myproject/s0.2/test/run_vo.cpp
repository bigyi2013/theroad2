// -------------- test the visual odometry -------------
#include <fstream>
#include <boost/timer.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/viz.hpp>


#include "myslam/config.h"
#include "myslam/visual_odometry.h"


int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: run_vo parameter_file" << endl;
        return 1;
    }

    myslam::Config::setParameterFile(argv[1]);
    myslam::VisualOdometry::Ptr vo(new myslam::VisualOdometry);

    string dataset_dir = myslam::Config::get<string>("dataset_dir");
    cout << "dataset: " << dataset_dir << endl;
    ifstream fin(dataset_dir + "/associate.txt");
    if (!fin) {
        cout << "please generate the associate file called associate.txt!" << endl;
        return 1;
    }

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

    // cout<<"read total "<<rgb_files.size() <<" entries"<<endl;
    cv::VideoCapture inputVideo;
    inputVideo.open(0);

    //   for ( int i=0; i<rgb_files.size(); i++ )
    if (!inputVideo.isOpened()) {
        cout << "video open 不了，我回乱说？" << endl;
        return 1;
    }
    //grab(),从视频文件或捕获设备抓取下一个帧。
    while (inputVideo.grab()) {
        cv::Mat image;
        //寻找二维码,while找到二维码
        myslam::Frame::Ptr pFrame = myslam::Frame::createFrame();
        pFrame->camera_ = camera;
        pFrame->color_=image;
        boost::timer timer;
        vo->charuco(image);
        //  vo->addFrame(pFrame); 这一步是关键。
        vo->addFrame(pFrame);

        cout << "VO costs time: " << timer.elapsed() << endl;
//        if (vo->state_ == myslam::VisualOdometry::LOST)
//            break;
        SE3 Tcw = pFrame->T_c_w_.inverse();

        // show the map and the camera pose
        cv::Affine3d M(
                cv::Affine3d::Mat3(
                        Tcw.rotation_matrix()(0, 0), Tcw.rotation_matrix()(0, 1), Tcw.rotation_matrix()(0, 2),
                        Tcw.rotation_matrix()(1, 0), Tcw.rotation_matrix()(1, 1), Tcw.rotation_matrix()(1, 2),
                        Tcw.rotation_matrix()(2, 0), Tcw.rotation_matrix()(2, 1), Tcw.rotation_matrix()(2, 2)
                ),
                cv::Affine3d::Vec3(
                        Tcw.translation()(0, 0), Tcw.translation()(1, 0), Tcw.translation()(2, 0)
                )
        );

        cv::imshow("image", image);
        cv::waitKey(1);
        vis.setWidgetPose("Camera", M);
        vis.spinOnce(1, false);
    }


    return 0;
}
