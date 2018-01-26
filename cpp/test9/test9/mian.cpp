#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
int test() {
	cv::Mat rvec = (cv::Mat_<double>(3, 3) << 1.5, 0.9,-1.5);
	cv::Matx33f r;
	cv::Rodrigues(rvec, r);

	return 0;
}

