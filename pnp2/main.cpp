#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/aruco.hpp"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <g2o/core/base_vertex.h>
#include <g2o/core/base_unary_edge.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/solvers/csparse/linear_solver_csparse.h>
#include <g2o/types/sba/types_six_dof_expmap.h>
#include <chrono>
using namespace std;
using namespace cv;
typedef float Matrix[3][3];


cv::Mat DoubleMatFromVec3b(cv::Vec3d in)
{
	cv::Mat mat(3, 1, CV_64FC1);
	mat.at <double>(0, 0) = in[0];
	mat.at <double>(1, 0) = in[1];
	mat.at <double>(2, 0) = in[2];
	return mat;
}
void bundleAdjustment (
    const vector< Point3f > points_3d,
    const vector< Point2f > points_2d,
    const Mat& K,
    Mat& R, Mat& t )
{
    // 初始化g2o
    typedef g2o::BlockSolver< g2o::BlockSolverTraits<6,3> > Block;  // pose 维度为 6, landmark 维度为 3
    Block::LinearSolverType* linearSolver = new g2o::LinearSolverCSparse<Block::PoseMatrixType>(); // 线性方程求解器
    Block* solver_ptr = new Block ( linearSolver );     // 矩阵块求解器
    g2o::OptimizationAlgorithmLevenberg* solver = new g2o::OptimizationAlgorithmLevenberg ( solver_ptr );
    g2o::SparseOptimizer optimizer;
    optimizer.setAlgorithm ( solver );

    // vertex
    g2o::VertexSE3Expmap* pose = new g2o::VertexSE3Expmap(); // camera pose
    Eigen::Matrix3d R_mat;
    R_mat <<
          R.at<double> ( 0,0 ), R.at<double> ( 0,1 ), R.at<double> ( 0,2 ),
               R.at<double> ( 1,0 ), R.at<double> ( 1,1 ), R.at<double> ( 1,2 ),
               R.at<double> ( 2,0 ), R.at<double> ( 2,1 ), R.at<double> ( 2,2 );
    pose->setId ( 0 );
    pose->setEstimate ( g2o::SE3Quat (
                            R_mat,
                            Eigen::Vector3d ( t.at<double> ( 0,0 ), t.at<double> ( 1,0 ), t.at<double> ( 2,0 ) )
                        ) );
    optimizer.addVertex ( pose );

    int index = 1;
    for ( const Point3f p:points_3d )   // landmarks
    {
        g2o::VertexSBAPointXYZ* point = new g2o::VertexSBAPointXYZ();
        point->setId ( index++ );
        point->setEstimate ( Eigen::Vector3d ( p.x, p.y, p.z ) );
        point->setMarginalized ( true ); // g2o 中必须设置 marg 参见第十讲内容
        optimizer.addVertex ( point );
    }

    // parameter: camera intrinsics
    g2o::CameraParameters* camera = new g2o::CameraParameters (
        K.at<double> ( 0,0 ), Eigen::Vector2d ( K.at<double> ( 0,2 ), K.at<double> ( 1,2 ) ), 0
    );
    camera->setId ( 0 );
    optimizer.addParameter ( camera );

    // edges
    index = 1;
    for ( const Point2f p:points_2d )
    {
        g2o::EdgeProjectXYZ2UV* edge = new g2o::EdgeProjectXYZ2UV();
        edge->setId ( index );
        edge->setVertex ( 0, dynamic_cast<g2o::VertexSBAPointXYZ*> ( optimizer.vertex ( index ) ) );
        edge->setVertex ( 1, pose );
        edge->setMeasurement ( Eigen::Vector2d ( p.x, p.y ) );
        edge->setParameterId ( 0,0 );
        edge->setInformation ( Eigen::Matrix2d::Identity() );
        optimizer.addEdge ( edge );
        index++;
    }

    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    optimizer.setVerbose ( true );
    optimizer.initializeOptimization();
    optimizer.optimize ( 100 );
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>> ( t2-t1 );
    cout<<"optimization costs time: "<<time_used.count() <<" seconds."<<endl;

    cout<<endl<<"after optimization:"<<endl;
    cout<<"T="<<endl<<Eigen::Isometry3d ( pose->estimate() ).matrix() <<endl;
}

int main(){
	cv::VideoCapture inputVideo;
	Matrix RR;

	inputVideo.open(0);
	cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 876.54585602, 0, 353.21887271, 0, 876.30286197, 198.42897486, 0, 0, 1);
	cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -0.11425339, 1.38441799, 0.0079628, 0.01205705, -3.59133568);
	// camera parameters are read from somewhere
	cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
	//cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
	while (inputVideo.grab()) {
		cv::Mat image, imageCopy;
		inputVideo.retrieve(image);
		image.copyTo(imageCopy);
		std::vector<int> ids;
		std::vector<std::vector<cv::Point2f > > corners;
		//std::vector<cv::Point3f> objpoint;
		//std::vector<cv::Point2f> imgpoints;
		 vector<Point2f> imgpoints;
		 vector<Point3f> objpoints;
		cv::aruco::detectMarkers(image, dictionary, corners, ids);
		// if at least one marker detected
		if (ids.size() > 0) {
			cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
			imgpoints.push_back(corners[0][0]);
			imgpoints.push_back(corners[0][1]);
			imgpoints.push_back(corners[0][2]);
			imgpoints.push_back(corners[0][3]);
			objpoints.push_back(cv::Vec3f(-0.2 / 2.f, 0.2 / 2.f, 0));
		        objpoints.push_back (cv::Vec3f(0.2 / 2.f, 0.2 / 2.f, 0));
                        objpoints.push_back ( cv::Vec3f(0.2 / 2.f, -0.2 / 2.f, 0));
                        objpoints.push_back( cv::Vec3f(-0.2 / 2.f, -0.2 / 2.f, 0));
		
			Mat r, t;
		//	Mat K = ( Mat_<double> ( 3,3 ) << 520.9, 0, 325.1, 0, 521.0, 249.7, 0, 0, 1 );
                        solvePnP ( objpoints, imgpoints, cameraMatrix, distCoeffs, r, t, false ); // 调用OpenCV 的 PnP 求解，可选择EPNP，DLS等方法
		        Mat Rpnp;
                        cv::Rodrigues ( r, Rpnp ); // r为旋转向量形式，用Rodrigues公式转换为矩阵

                        cout<<"R="<<endl<<R<<endl;
                       // cout<<"t="<<endl<<t<<endl;
		        std::vector<cv::Vec3d> rvecs, tvecs;
			//vector< cv::Mat > rvecs, tvecs;
			cv::aruco::estimatePoseSingleMarkers(corners, 0.2, cameraMatrix, distCoeffs, rvecs, tvecs);
			// draw axis for each marker
			for (int i = 0; i < ids.size(); i++){
				cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
				Mat R; 
				cv::Rodrigues(rvecs[i], R);
				cout << "旋转矩阵=" << R << endl;
				cv::Mat R_1;
	                        cv::Mat pos;
				R_1 = R.inv();
				//cout << "旋转矩阵的逆=" << R_1 << endl;
				//cout << "平移向量=" << tvecs[i] << endl;
				R = DoubleMatFromVec3b(tvecs[i]);
				//cout << "平移向量转换后=" << R << endl;
				pos = R_1*(-R);
				//cout << "相机位置：\n" << "X轴：" << pos.at<double>(0, 0) << endl;
				//cout << pos.at<double>(0, 0) << endl;
				//cout << "Y轴：" << pos.at<double>(1, 0) << endl;
				//cout << "Z轴：" << pos.at<double>(2, 0) << endl << endl;
			}	
		}

		cv::imshow("out", imageCopy);

		char key = (char)cv::waitKey(1);
		if (key == 27)
			break;
	}
	return 0;
	
}