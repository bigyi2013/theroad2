

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "mysurf.h"
using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;
/* @function main */
bool isRotationMatrix(Mat &R)
{
	Mat Rt;
	transpose(R, Rt);
	Mat shouldBeIdentity = Rt * R;
	Mat I = Mat::eye(3, 3, shouldBeIdentity.type());

	return  norm(I, shouldBeIdentity) < 1e-6;

}

// Calculates rotation matrix to euler angles
// The result is the same as MATLAB except the order
// of the euler angles ( x and z are swapped ).
Vec3f rotationMatrixToEulerAngles(Mat &R)
{

	assert(isRotationMatrix(R));

	float sy = sqrt(R.at<double>(0, 0) * R.at<double>(0, 0) + R.at<double>(1, 0) * R.at<double>(1, 0));

	bool singular = sy < 1e-6; // If

	float x, y, z;
	if (!singular)
	{
		x = atan2(R.at<double>(2, 1), R.at<double>(2, 2));
		y = atan2(-R.at<double>(2, 0), sy);
		z = atan2(R.at<double>(1, 0), R.at<double>(0, 0));
	}
	else
	{
		x = atan2(-R.at<double>(1, 2), R.at<double>(1, 1));
		y = atan2(-R.at<double>(2, 0), sy);
		z = 0;
	}
	return Vec3f(x, y, z);
}
float mysurf::match_size(Mat img_object, Mat img_scene, int minHessian , float ratio_thresh ) {

	Ptr<SURF> detector = SURF::create(minHessian);
	std::vector<KeyPoint> keypoints_object, keypoints_scene;
	Mat descriptors_object, descriptors_scene;
	detector->detectAndCompute(img_object, Mat(), keypoints_object, descriptors_object);
	detector->detectAndCompute(img_scene, Mat(), keypoints_scene, descriptors_scene);
	//-- Step 2: Matching descriptor vectors with a FLANN based matcher
	// Since SURF is a floating-point descriptor NORM_L2 is used
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
	std::vector< std::vector<DMatch> > knn_matches;
	matcher->knnMatch(descriptors_object, descriptors_scene, knn_matches, 2);
	//-- Filter matches using the Lowe's ratio test
	//const float ratio_thresh = 0.75f;
	std::vector<DMatch> good_matches;
	for (size_t i = 0; i < knn_matches.size(); i++)
	{
		if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance)
		{
			good_matches.push_back(knn_matches[i][0]);
		}
	}
	//-- Draw matches
	//Mat img_matches;
	//	drawMatches(img_object, keypoints_object, img_scene, keypoints_scene, good_matches, img_matches, Scalar::all(-1),
	//		Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < good_matches.size(); i++)
	{
		//-- Get the keypoints from the good matches
		obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
		scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
	}
	return good_matches.size();
}
float mysurf::getR() {
	//std::vector<Point2f> obj, std::vector<Point2f> scene
	Mat H = findHomography(obj, scene, RANSAC, 3, noArray(), 2000, 0.995);
	//std::cout << "H:" << std::endl;
	// std::cout << H << std::endl;
	cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
		<< 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
		8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
	vector<Mat> Rs_decomp, ts_decomp, normals_decomp;
	Mat rvec1, tvec1;
	int solutions = decomposeHomographyMat(H, cameraMatrix, Rs_decomp, ts_decomp, normals_decomp);

	//cout << "# r:                        \t" << Rs_decomp[i] << endl;
	if (isRotationMatrix(Rs_decomp[0]))
	{
		Vec3f oula = rotationMatrixToEulerAngles(Rs_decomp[0]);
		float z = oula[2] * 180 / 3.14159265358979323846;
		return z;
		//cout << "z" << oula[2] * 180 / 3.14159265358979323846 << endl;
	}
	else
	{
		return -1;
		//cout << "can not get r" << endl;
	}
}

