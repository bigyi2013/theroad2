@@ -1,125 +0,0 @@
// surf2.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
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
int main(int argc, char* argv[])
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
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	vector<DMatch> good_matches;
	for (size_t i = 0; i < nn_matches.size(); i++) {
		DMatch first = nn_matches[i][0];
		float dist1 = nn_matches[i][0].distance;
		float dist2 = nn_matches[i][1].distance;
		if (dist1 < nn_match_ratio * dist2) {
			matched1.push_back(kpts1[first.queryIdx]);
			matched2.push_back(kpts2[first.trainIdx]);
			obj.push_back(kpts1[first.queryIdx].pt);
			scene.push_back(kpts2[first.trainIdx].pt);
		}
	}
	//��õ�Ӧ�Ծ��� 
	std::vector<Point2f> obj2;
	std::vector<Point2f> scene2;
	Mat homography = findHomography(obj, scene, RANSAC);
	Mat result;
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
			obj2.push_back(matched1[i].pt);
			scene2.push_back(matched2[i].pt);
			good_matches.push_back(DMatch(new_i, new_i, 0));
		}
	}

	Mat homography2 = findHomography(obj2, scene2, RANSAC);
	std::cout << "H����" << std::endl;
	std::cout << homography << std::endl;
	std::cout << "H2����" << std::endl;
	std::cout << homography2 << std::endl;
	//�ֽⵥӦ�Ծ���
	cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
		<< 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
		8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
	cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -1.0666525029122846e-01, 3.3794337314215589e-01,
		1.6656304800872223e-05, -3.7943927324066247e-03,
		4.9543475405042214e-01);
	vector<Mat> Rs_decomp, ts_decomp, normals_decomp;
	int solutions = decomposeHomographyMat(homography, cameraMatrix, Rs_decomp, ts_decomp, normals_decomp);

	//�ֽⵥӦ�Ծ������
	drawMatches(img1, inliers1, img2, inliers2, good_matches, result);
	imwrite("result.png", result);
	//����start
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
	//����end
	double inlier_ratio = inliers1.size() * 1.0 / matched1.size();
	cout << "A-KAZE Matching Results" << endl;
	cout << "*******************************" << endl;
	cout << "# Keypoints 1:                        \t" << kpts1.size() << endl;
	cout << "# Keypoints 2:                        \t" << kpts2.size() << endl;
	cout << "# r:                        \t" << Rs_decomp[0]<< endl;
	cout << "# t:                        \t" <<ts_decomp[0] << endl;
	cout << "# Matches��ƥ��㣩:                            \t" << matched1.size() << endl;
	cout << "# Inliers����ȷƥ��㣩:                            \t" << inliers1.size() << endl;
	cout << "# Inliers Ratio�����Ŷȣ�:                      \t" << inlier_ratio << endl;
	cout << endl;
	imshow("akaze", result);
	waitKey();
	return 0;
}

