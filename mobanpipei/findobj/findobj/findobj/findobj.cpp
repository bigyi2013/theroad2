//// findobj.cpp : 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//
//#include <stdio.h>
//#include <iostream>
//#include "opencv2/core.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/features2d.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/calib3d.hpp"
//#include "opencv2/xfeatures2d.hpp"
//using namespace cv;
//using namespace cv::xfeatures2d;
//using namespace std;
//void readme();
///* @function main */
//int main(int argc, char** argv)
//{
//	if (argc != 3)
//	{
//		readme(); return -1;
//	}
//	Mat img_object = imread(argv[1], IMREAD_GRAYSCALE);
//	Mat img_scene = imread(argv[2], IMREAD_GRAYSCALE);
//	if (!img_object.data || !img_scene.data)
//	{
//		std::cout << " --(!) Error reading images " << std::endl; return -1;
//	}
//	//-- Step 1: Detect the keypoints and extract descriptors using SURF
//	int minHessian = 200;
//	Ptr<SURF> detector = SURF::create(minHessian, 10,3, true, false);
//	std::vector<KeyPoint> keypoints_object, keypoints_scene;
//	Mat descriptors_object, descriptors_scene;
//	detector->detectAndCompute(img_object, Mat(), keypoints_object, descriptors_object);
//	detector->detectAndCompute(img_scene, Mat(), keypoints_scene, descriptors_scene);
//	//-- Step 2: Matching descriptor vectors using FLANN matcher
//	FlannBasedMatcher matcher;
//	std::vector< DMatch > matches;
//	matcher.match(descriptors_object, descriptors_scene, matches);
//	double max_dist = 0; double min_dist = 100;
//	//-- Quick calculation of max and min distances between keypoints
//	for (int i = 0; i < descriptors_object.rows; i++)
//	{
//		double dist = matches[i].distance;
//		if (dist < min_dist) min_dist = dist;
//		if (dist > max_dist) max_dist = dist;
//	}
//	printf("-- Max dist : %f \n", max_dist);
//	printf("-- Min dist : %f \n", min_dist);
//	//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
//	std::vector< DMatch > good_matches;
//	for (int i = 0; i < descriptors_object.rows; i++)
//	{
//		if (matches[i].distance < 3 * min_dist)
//		{
//			good_matches.push_back(matches[i]);
//		}
//	}
//	Mat img_matches;
//	drawMatches(img_object, keypoints_object, img_scene, keypoints_scene,
//		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
//		std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
//	//-- Localize the object
//	std::vector<Point2f> obj;
//	std::vector<Point2f> scene;
//	for (size_t i = 0; i < good_matches.size(); i++)
//	{
//		//-- Get the keypoints from the good matches
//		obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
//		scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
//	}
//	Mat H = findHomography(obj, scene, RANSAC,3,noArray(),2000,0.995);
//	std::cout << "H矩阵：" << std::endl;
//	std::cout << H << std::endl;
//	//-- Get the corners from the image_1 ( the object to be "detected" )
//	std::vector<Point2f> obj_corners(4);
//	obj_corners[0] = cvPoint(0, 0); obj_corners[1] = cvPoint(img_object.cols, 0);
//	obj_corners[2] = cvPoint(img_object.cols, img_object.rows); obj_corners[3] = cvPoint(0, img_object.rows);
//	std::vector<Point2f> scene_corners(4);
//	perspectiveTransform(obj_corners, scene_corners, H);
//	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
//	line(img_matches, scene_corners[0] + Point2f(img_object.cols, 0), scene_corners[1] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	line(img_matches, scene_corners[1] + Point2f(img_object.cols, 0), scene_corners[2] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	line(img_matches, scene_corners[2] + Point2f(img_object.cols, 0), scene_corners[3] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	line(img_matches, scene_corners[3] + Point2f(img_object.cols, 0), scene_corners[0] + Point2f(img_object.cols, 0), Scalar(0, 255, 0), 4);
//	//-- Show detected matches
//	Mat littleimg;
//	resize(img_matches, littleimg, Size(img_matches.cols / 3, img_matches.rows / 3), 0, 0, INTER_LINEAR);
//	imshow("Good Matches & Object detection", littleimg);
//	waitKey(0);
//	return 0;
//}
///* @function readme */
//void readme()
//{
//	std::cout << " Usage: ./SURF_descriptor <img1> <img2>" << std::endl;
//}
#include "stdafx.h"
#include <stdio.h>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/calib3d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include <iostream>
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
const float inlier_threshold = 2.5f; // Distance threshold to identify inliers
const float nn_match_ratio = 0.8f;   // Nearest neighbor matching ratio
int surfandakaze(int argc, char* argv[])
{
	CommandLineParser parser(argc, argv,
		"{@img1 | ../data/graf1.png | input image 1}"
		"{@img2 | ../data/graf3.png | input image 2}"
		"{@homography | ../data/H1to3p.xml | homography matrix}");
	Mat img1 = imread(parser.get<String>("@img1"), IMREAD_GRAYSCALE);
	Mat img2 = imread(parser.get<String>("@img2"), IMREAD_GRAYSCALE);
	//Mat homography;
	//FileStorage fs(parser.get<String>("@homography"), FileStorage::READ);
	//fs.getFirstTopLevelNode() >> homography;
	vector<KeyPoint> kpts1, kpts2;
	Mat desc1, desc2;
	Ptr<AKAZE> akaze = AKAZE::create();
	akaze->detectAndCompute(img1, noArray(), kpts1, desc1);
	akaze->detectAndCompute(img2, noArray(), kpts2, desc2);
	BFMatcher matcher(NORM_HAMMING);
	vector< vector<DMatch> > nn_matches;
	matcher.knnMatch(desc1, desc2, nn_matches, 2);
	vector<KeyPoint> matched1, matched2, inliers1, inliers2;
	vector<DMatch> good_matches;
	for (size_t i = 0; i < nn_matches.size(); i++) {
		DMatch first = nn_matches[i][0];
		float dist1 = nn_matches[i][0].distance;
		float dist2 = nn_matches[i][1].distance;
		if (dist1 < nn_match_ratio * dist2) {
			matched1.push_back(kpts1[first.queryIdx]);
			matched2.push_back(kpts2[first.trainIdx]);
		}
	}
	//获得单应性矩阵 start
	//-- Step 1: Detect the keypoints and extract descriptors using SURF
	int minHessian = 400;
	Ptr<SURF> detector = SURF::create(minHessian);
	std::vector<KeyPoint> keypoints_object, keypoints_scene;
	Mat descriptors_object, descriptors_scene;
	detector->detectAndCompute(img1, Mat(), keypoints_object, descriptors_object);
	detector->detectAndCompute(img2, Mat(), keypoints_scene, descriptors_scene);
	//-- Step 2: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher2;
	std::vector< DMatch > matches;
	matcher2.match(descriptors_object, descriptors_scene, matches);
	double max_dist = 0; double min_dist = 100;
	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_object.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}
	printf("-- Max dist : %f \n", max_dist);
	printf("-- Min dist : %f \n", min_dist);
	//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
	std::vector< DMatch > good_matches2;
	for (int i = 0; i < descriptors_object.rows; i++)
	{
		if (matches[i].distance <= 3 * min_dist)
		{
			good_matches2.push_back(matches[i]);
		}
	}
	Mat result;
		drawMatches(img1, keypoints_object, img2, keypoints_scene,
			good_matches, result, Scalar::all(-1), Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < good_matches2.size(); i++)
	{
		//-- Get the keypoints from the good matches
		obj.push_back(keypoints_object[good_matches2[i].queryIdx].pt);
		scene.push_back(keypoints_scene[good_matches2[i].trainIdx].pt);
	}
	Mat homography = findHomography(obj, scene, RANSAC);
	std::cout << "H矩阵：" << std::endl;
	std::cout << homography << std::endl;
	//获得单应性矩阵  end
	for (unsigned i = 0; i < matched1.size(); i++) {
		Mat col = Mat::ones(3, 1, CV_64F);
		col.at<double>(0) = matched1[i].pt.x;
		col.at<double>(1) = matched1[i].pt.y;
		col = homography * col;
		col /= col.at<double>(2);
		double dist = sqrt(pow(col.at<double>(0) - matched2[i].pt.x, 2) +
			pow(col.at<double>(1) - matched2[i].pt.y, 2));
		if (dist < inlier_threshold) {
			int new_i = static_cast<int>(inliers1.size());
			inliers1.push_back(matched1[i]);
			inliers2.push_back(matched2[i]);
			good_matches.push_back(DMatch(new_i, new_i, 0));
		}
	}
	drawMatches(img1, inliers1, img2, inliers2, good_matches, result);
	imwrite("result.png", result);
	//画框start
	//-- Get the corners from the image_1 ( the object to be "detected" )
	std::vector<Point2f> obj_corners(4);
	obj_corners[0] = cvPoint(0, 0); obj_corners[1] = cvPoint(img1.cols, 0);
	obj_corners[2] = cvPoint(img1.cols, img1.rows); obj_corners[3] = cvPoint(0, img1.rows);
	std::vector<Point2f> scene_corners(4);
	perspectiveTransform(obj_corners, scene_corners, homography);
	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
	line(result, scene_corners[0] + Point2f(img1.cols, 0), scene_corners[1] + Point2f(img1.cols, 0), Scalar(0, 255, 0), 4);
	line(result, scene_corners[1] + Point2f(img1.cols, 0), scene_corners[2] + Point2f(img1.cols, 0), Scalar(0, 255, 0), 4);
	line(result, scene_corners[2] + Point2f(img1.cols, 0), scene_corners[3] + Point2f(img1.cols, 0), Scalar(0, 255, 0), 4);
	line(result, scene_corners[3] + Point2f(img1.cols, 0), scene_corners[0] + Point2f(img1.cols, 0), Scalar(0, 255, 0), 4);
	//-- Show detected matches
	//画框end
	double inlier_ratio = inliers1.size() * 1.0 / matched1.size();
	cout << "A-KAZE Matching Results" << endl;
	cout << "*******************************" << endl;
	cout << "# Keypoints 1:                        \t" << kpts1.size() << endl;
	cout << "# Keypoints 2:                        \t" << kpts2.size() << endl;
	cout << "# Matches（匹配点）:                            \t" << matched1.size() << endl;
	cout << "# Inliers（正确匹配点）:                            \t" << inliers1.size() << endl;
	cout << "# Inliers Ratio（可信度）:                      \t" << inlier_ratio << endl;
	cout << endl;
	imshow("result", result);
	waitKey();
	return 0;
}