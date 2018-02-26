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

  //Rect_(_Tp _x, _Tp _y, _Tp _width, _Tp _height)������һ�����Ͻǵ�����Ϊ(_x, _y)��_width*_height���δ��ڣ�
  Rect roi(114, 130, 90, 120);
  //Rect roi(210, 650, 90, 120);
  Mat roi_of_image = img_1(roi);
  img_1 = roi_of_image;
  //��һ������Surf���Ӽ��ؼ���------------------------1
  int minHessian = 400;
 
  SurfFeatureDetector detector( minHessian );

  std::vector<KeyPoint> keypoints_1, keypoints_2;//����2��ר���ɵ���ɵĵ����������洢������

  detector.detect( img_1, keypoints_1 );//��img_1ͼ���м�⵽��������洢��������keypoints_1��
  detector.detect( img_2, keypoints_2 );//ͬ��

  //�ڶ�����������������------------------------2
  SurfDescriptorExtractor extractor;

  Mat descriptors_1, descriptors_2;//������������ľ���

  extractor.compute( img_1, keypoints_1, descriptors_1 );//������������
  extractor.compute( img_2, keypoints_2, descriptors_2 );

  //��������ƥ����������
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

  //ƥ�����л��Ʒ���
  //����ԭ�������ú�����findHomography���� ������������ͼ��ĵ�Ӧ�Ծ�����߽У���ӳ����󣩣�����һ��3*3�ľ���findHomography�� ��������ά���֮������ŵ�ӳ��任���� H��3��x3�У� ��ʹ����С����������RANSAC���� ��
  std::vector<Point2f> obj;
  std::vector<Point2f> scene;
  for (unsigned int i = 0; i < good_matches.size(); i++)
  {
	  obj.push_back(keypoints_1[good_matches[i].queryIdx].pt);//ԭͼ�д���������������
	  scene.push_back(keypoints_2[good_matches[i].trainIdx].pt);//ƥ��ͼ�д���������������
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
	  //good_matches[i].queryIdx�����ŵ�һ��ͼƬƥ������ţ� keypoints_1[good_matches[i].queryIdx].pt.x Ϊ����Ŷ�Ӧ�ĵ��x���ꡣy����ͬ��
	  //good_matches[i].trainIdx�����ŵڶ���ͼƬƥ������ţ�keypoints_2[good_matches[i].trainIdx].pt.x ΪΪ����Ŷ�Ӧ�ĵ��x���ꡣy����ͬ��
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
  //��Ӧ�Ծ���������ͶӰ���ƫ���� scene_corners[0]��������ƥ��ͼ���еĵ��λ�ã���ΪЧ��ͼ���൱��������һ����ƥ��ͼ��Ŀ�ȣ�����ÿһ���㶼Ҫ����Point2f( img_x.cols, 0)
  Moments dstMoments = moments(scene_corners);//����ͼ��ľ�
  double centerx = dstMoments.m10 / dstMoments.m00;//�õ���������x
  double centery = dstMoments.m01 / dstMoments.m00;//�õ���������y
  line(img_matches, scene_corners[0] + Point2f(img_x.cols, 0), scene_corners[1] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[1] + Point2f(img_x.cols, 0), scene_corners[2] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[2] + Point2f(img_x.cols, 0), scene_corners[3] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[3] + Point2f(img_x.cols, 0), scene_corners[0] + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);
  line(img_matches, scene_corners[0] + Point2f(img_x.cols, 0), Point2f(centerx, centery) + Point2f(img_x.cols, 0), Scalar(0, 255, 0), 4);//�������ϵ㵽���ĵ��߶�
  

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
