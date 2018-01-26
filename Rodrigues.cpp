/*
 * Rodrigues.cpp
 *
 *  Created/home/yehoo/apriltags/example/apriltags_demo.cpp on: Oct 23, 2017
 *      Author: yehoo
 */

using namespace std;
#include "opencv2/opencv.hpp"
int main(){
	cv::Mat rvec = (cv::Mat_<float>(3,3) <<  0.5,0.5, 0.5);
	cv::Matx33f r;
	cv::Rodrigues(rvec,r);
	return 0;
}

