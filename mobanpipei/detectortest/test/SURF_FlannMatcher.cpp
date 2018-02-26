/**
 * @file SURF_FlannMatcher
 * @brief SURF detector + descriptor + FLANN Matcher
 * @author A. Huaman
 */

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/legacy/legacy.hpp>
using namespace cv;

void readme();

/**
 * @function main
 * @brief Main function
 */
int main( int argc, char** argv )
{
  if( argc != 3 )
  { readme(); return -1; }

  Mat img_1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  Mat img_2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);

  if( !img_1.data || !img_2.data )
  { std::cout<< " --(!) Error reading images " << std::endl; return -1; }

  Mat img_x = img_1;

  //Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height)，定义一个左上角点坐标为(_x, _y)的_width*_height矩形窗口；
  Rect roi(114, 130, 90, 120);
  //Rect roi(210, 650, 90, 120);
  Mat roi_of_image = img_1(roi);
  img_1 = roi_of_image;
  //第一步，用Surf算子检测关键点------------------------1
  int minHessian = 400;
 
  SurfFeatureDetector detector( minHessian );

  std::vector<KeyPoint> keypoints_1, keypoints_2;//构造2个专门由点组成的点向量用来存储特征点

  detector.detect( img_1, keypoints_1 );//将img_1图像中检测到的特征点存储起来放在keypoints_1中
  detector.detect( img_2, keypoints_2 );//同理

  //第二步，计算特征向量------------------------2
  SurfDescriptorExtractor extractor;

  Mat descriptors_1, descriptors_2;//存放特征向量的矩阵

  extractor.compute( img_1, keypoints_1, descriptors_1 );//计算特征向量
  extractor.compute( img_2, keypoints_2, descriptors_2 );

  //第三步，匹配特征向量
  FlannBasedMatcher matcher;
  std::vector< DMatch > matches;
  matcher.match( descriptors_1, descriptors_2, matches );

  double max_dist = 0; double min_dist = 100;

  //-- Quick calculation of max and min distances between keypoints
  for( int i = 0; i < descriptors_1.rows; i++ )
  { double dist = matches[i].distance;
    if( dist < min_dist ) min_dist = dist;
    if( dist > max_dist ) max_dist = dist;
  }

  printf("-- Max dist : %f \n", max_dist );
  printf("-- Min dist : %f \n", min_dist );

  //-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
  //-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
  //-- small)
  //-- PS.- radiusMatch can also be used here.
  std::vector< DMatch > good_matches;

  for( int i = 0; i < descriptors_1.rows; i++ )
  { if( matches[i].distance <= max(2*min_dist, 0.02) )
    { good_matches.push_back( matches[i]); }
  }

  //匹配结果中绘制方框
  //基本原理是利用函数：findHomography，该 函数是求两幅图像的单应性矩阵或者叫（单映射矩阵），它是一个3*3的矩阵。findHomography： 计算多个二维点对之间的最优单映射变换矩阵 H（3行x3列） ，使用最小均方误差或者RANSAC方法 。
  std::vector<Point2f> obj;
  std::vector<Point2f> scene;
  for (unsigned int i = 0; i < good_matches.size(); i++)
  {
	  obj.push_back(keypoints_1[good_matches[i].queryIdx].pt);//原图中待检测物体的特征点
	  scene.push_back(keypoints_2[good_matches[i].trainIdx].pt);//匹配图中待检测物体的特征点
  }
  Mat H = findHomography(obj, scene, CV_RANSAC);
  std::vector<Point2f> obj_corners(4);
  obj_corners[0] = cvPoint(0, 0);
  obj_corners[1] = cvPoint(img_1.cols, 0);
  obj_corners[2] = cvPoint(img_1.cols, img_1.rows);
  obj_corners[3] = cvPoint(0, img_1.rows);
  std::vector<Point2f> scene_corners(4);
  perspectiveTransform(obj_corners, scene_corners, H);



  //
  for (int i = 0; i < (int)good_matches.size(); i++)
  {
	  //good_matches[i].queryIdx保存着第一张图片匹配点的序号， keypoints_1[good_matches[i].queryIdx].pt.x 为该序号对应的点的x坐标。y坐标同理
	  //good_matches[i].trainIdx保存着第二张图片匹配点的序号，keypoints_2[good_matches[i].trainIdx].pt.x 为为该序号对应的点的x坐标。y坐标同理
	  keypoints_1[good_matches[i].queryIdx].pt.x = keypoints_1[good_matches[i].queryIdx].pt.x + 114;
	  keypoints_1[good_matches[i].queryIdx].pt.y = keypoints_1[good_matches[i].queryIdx].pt.y + 130;
	  printf("-- Good Match [%d] Keypoint 1(%f,%f): %d  -- Keypoint 2(%f,%f): %d  \n", i,
		  keypoints_1[good_matches[i].queryIdx].pt.x, keypoints_1[good_matches[i].queryIdx].pt.y, good_matches[i].queryIdx,
		  keypoints_2[good_matches[i].trainIdx].pt.x, keypoints_2[good_matches[i].trainIdx].pt.y, good_matches[i].trainIdx);
  }
  

  //-- Draw only "good" matches
  Mat img_matches;
  rectangle(img_x, roi, cvScalar(0, 0, 255), 2, 4, 0);
  drawMatches(img_x, keypoints_1, img_2, keypoints_2,
               good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
               vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );


  //-- Draw lines between the corners (the mapped object in the scene - image_2 )
  //单应性矩阵算过后的投影点的偏移量 scene_corners[0]，就是在匹配图像中的点的位置，因为效果图像相当于增加了一个待匹配图像的宽度，所以每一个点都要加上Point2f( img_x.cols, 0)
  Moments dstMoments = moments(scene_corners);//计算图像的矩
  double centerx = dstMoments.m10 / dstMoments.m00;//得到中心坐标x
  double centery = dstMoments.m01 / dstMoments.m00;//得到中心坐标y
  line(img_matches, scene_corners[0] + Point2f(img_x.cols, 0), scene_corners[1] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[1] + Point2f(img_x.cols, 0), scene_corners[2] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[2] + Point2f(img_x.cols, 0), scene_corners[3] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[3] + Point2f(img_x.cols, 0), scene_corners[0] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[0] + Point2f(img_x.cols, 0), Point2f(centerx, centery) + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);//绘制左上点到质心的线段
  

  //FileStorage fs("gg.yml", CV_STORAGE_WRITE);
  //if (fs.isOpened())
  //{
	 // fs << "M1" << img_matches;
	 // fs.release();
  //}
  //else
	 // printf( "Error: can not save the intrinsic parameters\n");

  //-- Show detected matches
  imshow( "Good Matches", img_matches );

  for( int i = 0; i < (int)good_matches.size(); i++ )
  { printf( "-- Good Match [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx ); }


  waitKey(0);

  return 0;
}

/**
 * @function readme
 */
void readme()
{ std::cout << " Usage: ./SURF_FlannMatcher <img1> <img2>" << std::endl; }
