/**
* @SURF�������Ⲣ����������
* @author holybin
*/

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"        //SiftFeatureDetectorʵ���ڸ�ͷ�ļ���
#include "opencv2/opencv.hpp"
#include <opencv2/legacy/legacy.hpp>
using namespace cv;
using namespace std;
void readme();

/** @function main */
int main(int argc,char* argv[])
{
    TickMeter tm;
    Mat img_1=imread("single0.jpg",CV_LOAD_IMAGE_GRAYSCALE);//�궨��ʱCV_LOAD_IMAGE_GRAYSCALE=0��Ҳ���Ƕ�ȡ�Ҷ�ͼ��
    Mat img_2=imread("double52.jpg",CV_LOAD_IMAGE_GRAYSCALE);//һ��Ҫ�ǵ�����·����б�߷�������Matlab�������෴��
    if(!img_1.data || !img_2.data)//�������Ϊ��
    {
        cout<<"opencv error"<<endl;
        return -1;
    }
    cout<<"open right"<<endl;
     tm.start();
///******************************����1 SURF**********************************/
//    //��һ������Surf���Ӽ��ؼ���------------------------1
//    SurfFeatureDetector detector;//���캯�������ڲ�Ĭ�ϵ�
//    std::vector<KeyPoint> keypoints_1,keypoints_2;//����2��ר���ɵ���ɵĵ����������洢������
//    detector.detect(img_1,keypoints_1);//��img_1ͼ���м�⵽��������洢��������keypoints_1��
//    detector.detect(img_2,keypoints_2);//ͬ��
//
//	printf("-- Ŀ��ͼ���������� : %d \n", keypoints_1.size());
//
//    //��ͼ���л���������
//    Mat img_keypoints_1,img_keypoints_2;
//    drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//���ڴ��л���������
//    drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
//
//    //������������-------------------------------------------2
//    SurfDescriptorExtractor extractor;
//    Mat descriptors_1,descriptors_2;//������������ľ���
//    extractor.compute(img_1,keypoints_1,descriptors_1);//������������
//    extractor.compute(img_2,keypoints_2,descriptors_2);
//
//    //��burte force����ƥ����������---------------------------3
//    BruteForceMatcher<L2<float> > matcher;//����һ��burte force matcher����
////    FlannBasedMatcher matcher;
//    vector<DMatch>matches;
//    matcher.match(descriptors_1,descriptors_2,matches);
///************************����2 SIFT****************************************/
//    SiftFeatureDetector detector;//���캯�������ڲ�Ĭ�ϵ�
//    std::vector<KeyPoint> keypoints_1,keypoints_2;//����2��ר���ɵ���ɵĵ����������洢������
//    detector.detect(img_1,keypoints_1);//��img_1ͼ���м�⵽��������洢��������keypoints_1��
//    detector.detect(img_2,keypoints_2);//ͬ��
//    Mat img_keypoints_1,img_keypoints_2;
//    drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//���ڴ��л���������
//    drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
//    SiftDescriptorExtractor extractor;//���������Ӷ���
//    Mat descriptors_1,descriptors_2;//������������ľ���
//    extractor.compute(img_1,keypoints_1,descriptors_1);//������������
//    extractor.compute(img_2,keypoints_2,descriptors_2);
////    BruteForceMatcher<L2<float> > matcher;//����һ��burte force matcher����
//    FlannBasedMatcher matcher;
//    vector<DMatch>matches;
//    matcher.match(descriptors_1,descriptors_2,matches);
/***************************����3 orb****************************************/
    OrbFeatureDetector detector;//���캯�������ڲ�Ĭ�ϵ�
    std::vector<KeyPoint> keypoints_1,keypoints_2;//����2��ר���ɵ���ɵĵ����������洢������
    detector.detect(img_1,keypoints_1);//��img_1ͼ���м�⵽��������洢��������keypoints_1��
    detector.detect(img_2,keypoints_2);//ͬ��

	printf("-- Ŀ��ͼ���������� : %d \n", keypoints_1.size());

    Mat img_keypoints_1,img_keypoints_2;
    drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//���ڴ��л���������
    drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
    OrbDescriptorExtractor extractor;//���������Ӷ���
    Mat descriptors_1,descriptors_2;//������������ľ���
    extractor.compute(img_1,keypoints_1,descriptors_1);//������������
    extractor.compute(img_2,keypoints_2,descriptors_2);
    BruteForceMatcher<L2<float> > matcher;//����һ��burte force matcher����
//    FlannBasedMatcher matcher; //can't use
    vector<DMatch>matches;
    matcher.match(descriptors_1,descriptors_2,matches);
/***************************orb****************************************/
    tm.stop();
    cout<<"time="<<tm.getTimeMilli()<<endl;
//    //����ƥ���߶�
//    Mat img_matches;
//    drawMatches(img_1,keypoints_1,img_2,keypoints_2,matches,img_matches);//��ƥ������Ľ�������ڴ�img_matches��
//    //��ʾƥ���߶�
//    imshow("sift_Matches",img_matches);//��ʾ�ı���ΪMatches

//    imshow("sift_keypoints_1",img_keypoints_1);//��ʾ������
//    imshow("sift_keypoints_2",img_keypoints_2);
/***************************************************************************/
    double max_dist = 0;
    double min_dist = 100;
    for( int i = 0; i < descriptors_1.rows; i++ )
    {
        double dist = matches[i].distance;
        if( dist < min_dist ) min_dist = dist;
        if( dist > max_dist ) max_dist = dist;
    }
    std::vector< DMatch > good_matches;
    for( int i = 0; i < descriptors_1.rows; i++ )
    {
        if( matches[i].distance < 3*min_dist )
        {
            good_matches.push_back( matches[i]);
        }
    }

	printf("-- ������ƥ����� : %d \n", keypoints_1.size());

    Mat img_matches;
    drawMatches( img_1,keypoints_1,img_2,keypoints_2,
                 good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
                 vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
    std::vector<Point2f> obj;
    std::vector<Point2f> scene;
    for(unsigned int i = 0; i < good_matches.size(); i++ )
    {
        obj.push_back( keypoints_1[ good_matches[i].queryIdx ].pt );
        scene.push_back( keypoints_2[ good_matches[i].trainIdx ].pt );
    }
    Mat H = findHomography( obj, scene, CV_RANSAC );
    std::vector<Point2f> obj_corners(4);
    obj_corners[0] = cvPoint(0,0);
    obj_corners[1] = cvPoint( img_1.cols, 0 );
    obj_corners[2] = cvPoint( img_1.cols, img_1.rows );
    obj_corners[3] = cvPoint( 0, img_1.rows );
    std::vector<Point2f> scene_corners(4);
    perspectiveTransform( obj_corners, scene_corners, H);
    //-- Draw lines between the corners (the mapped object in the scene - image_2 )
    line( img_matches, scene_corners[0] + Point2f( img_1.cols, 0), scene_corners[1] + Point2f( img_1.cols, 0), Scalar(0, 255, 0), 4 );
    line( img_matches, scene_corners[1] + Point2f( img_1.cols, 0), scene_corners[2] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    line( img_matches, scene_corners[2] + Point2f( img_1.cols, 0), scene_corners[3] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    line( img_matches, scene_corners[3] + Point2f( img_1.cols, 0), scene_corners[0] + Point2f( img_1.cols, 0), Scalar( 0, 255, 0), 4 );
    //-- Show detected matches
    imshow( "Good Matches & Object detection", img_matches );

	//RANSAC ������ƥ�������� ��Ҫ��Ϊ�������֣�
	//1������matches�����������,������ת��Ϊfloat����
	//2��ʹ����������󷽷� findFundamentalMat,�õ�RansacStatus
	//3������RansacStatus������ƥ��ĵ�Ҳ��RansacStatus[i]=0�ĵ�ɾ��

	//����matches�����������,������ת��Ϊfloat����
	vector<KeyPoint> R_keypoint01, R_keypoint02;
	for (size_t i = 0; i<matches.size(); i++)
	{
		R_keypoint01.push_back(keypoints_1[matches[i].queryIdx]);
		R_keypoint02.push_back(keypoints_2[matches[i].trainIdx]);
		//�����仰����⣺R_keypoint1��Ҫ�洢img01������img02ƥ��������㣬
		//matches�д洢����Щƥ���Ե�img01��img02������ֵ
	}

	//����ת��
	vector<Point2f>p01, p02;
	for (size_t i = 0; i<matches.size(); i++)
	{
		p01.push_back(R_keypoint01[i].pt);
		p02.push_back(R_keypoint02[i].pt);
	}

	//���û��������޳���ƥ���
	vector<uchar> RansacStatus;
	Mat Fundamental = findFundamentalMat(p01, p02, RansacStatus, FM_RANSAC);


	vector<KeyPoint> RR_keypoint01, RR_keypoint02;
	vector<DMatch> RR_matches;            //���¶���RR_keypoint ��RR_matches���洢�µĹؼ����ƥ�����
	int index = 0;
	for (size_t i = 0; i<matches.size(); i++)
	{
		if (RansacStatus[i] != 0)
		{
			RR_keypoint01.push_back(R_keypoint01[i]);
			RR_keypoint02.push_back(R_keypoint02[i]);
			matches[i].queryIdx = index;
			matches[i].trainIdx = index;
			RR_matches.push_back(matches[i]);
			index++;
		}
	}
	Mat img_RR_matches;
	drawMatches(img_1, RR_keypoint01, img_2, RR_keypoint02, RR_matches, img_RR_matches, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
	line(img_RR_matches, scene_corners[0] + Point2f(img_1.cols, 0), scene_corners[1] + Point2f(img_1.cols, 0), Scalar(0, 255, 0), 4);
	line(img_RR_matches, scene_corners[1] + Point2f(img_1.cols, 0), scene_corners[2] + Point2f(img_1.cols, 0), Scalar(0, 255, 0), 4);
	line(img_RR_matches, scene_corners[2] + Point2f(img_1.cols, 0), scene_corners[3] + Point2f(img_1.cols, 0), Scalar(0, 255, 0), 4);
	line(img_RR_matches, scene_corners[3] + Point2f(img_1.cols, 0), scene_corners[0] + Point2f(img_1.cols, 0), Scalar(0, 255, 0), 4);
	//-- Show detected matches
	imshow("������ƥ����", img_RR_matches);


    /**************************************************************************/
    waitKey(0);
    return 0;
}