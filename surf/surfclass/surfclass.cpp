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
int main(int argc, char** argv)
{

	Mat img_object = imread("../image.jpg", IMREAD_GRAYSCALE);
	Mat img_scene = imread("../image2.jpg", IMREAD_GRAYSCALE);

	//-- Step 1: Detect the keypoints and extract descriptors using SURF
	int minHessian = 400;
	//	Ptr<SURF> detector = SURF::create(minHessian, 4, 3, false, false);
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
	const float ratio_thresh = 0.75f;
	std::vector<DMatch> good_matches;
	for (size_t i = 0; i < knn_matches.size(); i++)
	{
		if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance)
		{
			good_matches.push_back(knn_matches[i][0]);
		}
	}
	//-- Draw matches
	Mat img_matches;
	drawMatches(img_object, keypoints_object, img_scene, keypoints_scene, good_matches, img_matches, Scalar::all(-1),
		Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < good_matches.size(); i++)
	{
		//-- Get the keypoints from the good matches
		obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
		scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
	}
	Mat H = findHomography(obj, scene, RANSAC, 3, noArray(), 2000, 0.995);
	//std::cout << "H:" << std::endl;
	// std::cout << H << std::endl;
	cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
		<< 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
		8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
	vector<Mat> Rs_decomp, ts_decomp, normals_decomp;
	Mat rvec1, tvec1;
	int solutions = decomposeHomographyMat(H, cameraMatrix, Rs_decomp, ts_decomp, normals_decomp);
	for (int i = 0; i < Rs_decomp.size(); i++)
	{
		//cout << "# r:                        \t" << Rs_decomp[i] << endl;
		if (isRotationMatrix(Rs_decomp[0]))
		{
			Vec3f oula = rotationMatrixToEulerAngles(Rs_decomp[i]);
			float z = oula[2] * 180 / 3.14159265358979323846;
			cout << "z" << oula[2] * 180 / 3.14159265358979323846 << endl;
		}
		else
		{
			return -1;
			//cout << "can not get r" << endl;
		}

	}
	//-- Get the corners from the image_1 ( the object to be "detected" )
	std::vector<Point2f> obj_corners(4);
	obj_corners[0] = cvPoint(0, 0); obj_corners[1] = cvPoint(img_object.cols, 0);
	obj_corners[2] = cvPoint(img_object.cols, img_object.rows); obj_corners[3] = cvPoint(0, img_object.rows);
	std::vector<Point2f> scene_corners(4);
	perspectiveTransform(obj_corners, scene_corners, H);
	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
	//line(img_matches, scene_corners[0] + Point2f(img_object.cols, 0), scene_corners[1] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	//line(img_matches, scene_corners[1] + Point2f(img_object.cols, 0), scene_corners[2] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	//line(img_matches, scene_corners[2] + Point2f(img_object.cols, 0), scene_corners[3] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	//line(img_matches, scene_corners[3] + Point2f(img_object.cols, 0), scene_corners[0] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
	//-- Show detected matches
	//Mat littleimg;

	//resize(img_matches, littleimg, Size(img_matches.cols, img_matches.rows), 0, 0, INTER_LINEAR);
	//imshow("surf", littleimg);
	//waitKey(0);
	system("pause");
	return 0;
}