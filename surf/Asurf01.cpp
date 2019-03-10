@@ -1,58 +0,0 @@
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
using namespace std;
typedef float Matrix[3][3];


cv::Mat DoubleMatFromVec3b(cv::Vec3d in)
{
	cv::Mat mat(3, 1, CV_64FC1);
	mat.at <double>(0, 0) = in[0];
	mat.at <double>(1, 0) = in[1];
	mat.at <double>(2, 0) = in[2];
	return mat;
}

int main(){
	cv::VideoCapture inputVideo;
	Matrix RR;
	cv::Mat R;
	cv::Mat R_1;
	cv::Mat pos;

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
		cv::aruco::detectMarkers(image, dictionary, corners, ids);
		// if at least one marker detected
		if (ids.size() > 0) {
			cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);
			vector< cv::Mat > rvecs, tvecs;
			cv::aruco::estimatePoseSingleMarkers(corners, 0.2, cameraMatrix, distCoeffs, rvecs, tvecs);
			// draw axis for each marker
			for (int i = 0; i < ids.size(); i++){
				cv::aruco::drawAxis(imageCopy, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.1);
				cv::Rodrigues(rvecs[i], R);
				R_1 = R.inv();
				R = DoubleMatFromVec3b(tvecs[i]);
				pos = R_1*(-R);
			}	
		}

		cv::imshow("out", imageCopy);

		char key = (char)cv::waitKey(1);
		if (key == 27)
			break;
	}
	return 0;
}