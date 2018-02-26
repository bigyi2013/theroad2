/**
* @SURF特征点检测并绘制特征点
* @author holybin
*/

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"        //SiftFeatureDetector实际在该头文件中
#include "opencv2/opencv.hpp"
#include <opencv2/legacy/legacy.hpp>
using namespace cv;
using namespace std;
void readme();

/** @function main */
int main(int argc,char* argv[])
{
    TickMeter tm;
    Mat img_1=imread("single0.jpg",CV_LOAD_IMAGE_GRAYSCALE);//宏定义时CV_LOAD_IMAGE_GRAYSCALE=0，也就是读取灰度图像
    Mat img_2=imread("double5.jpg",CV_LOAD_IMAGE_GRAYSCALE);//一定要记得这里路径的斜线方向，这与Matlab里面是相反的
    if(!img_1.data || !img_2.data)//如果数据为空
    {
        cout<<"opencv error"<<endl;
        return -1;
    }
    cout<<"open right"<<endl;
     tm.start();
/******************************方法1 SURF**********************************/
    //第一步，用Surf算子检测关键点------------------------1
    SurfFeatureDetector detector;//构造函数采用内部默认的
    std::vector<KeyPoint> keypoints_1,keypoints_2;//构造2个专门由点组成的点向量用来存储特征点
    detector.detect(img_1,keypoints_1);//将img_1图像中检测到的特征点存储起来放在keypoints_1中
    detector.detect(img_2,keypoints_2);//同理

	printf("-- 目标图像特征点数 : %d \n", keypoints_1.size());

    //在图像中画出特征点
    Mat img_keypoints_1,img_keypoints_2;
    drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//在内存中画出特征点
    drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);

    //计算特征向量-------------------------------------------2
    SurfDescriptorExtractor extractor;
    Mat descriptors_1,descriptors_2;//存放特征向量的矩阵
    extractor.compute(img_1,keypoints_1,descriptors_1);//计算特征向量
    extractor.compute(img_2,keypoints_2,descriptors_2);

    //用burte force进行匹配特征向量---------------------------3
    BruteForceMatcher<L2<float> > matcher;//定义一个burte force matcher对象
//    FlannBasedMatcher matcher;
    vector<DMatch>matches;
    matcher.match(descriptors_1,descriptors_2,matches);
/************************方法2 SIFT****************************************/
//    SiftFeatureDetector detector;//构造函数采用内部默认的
//    std::vector<KeyPoint> keypoints_1,keypoints_2;//构造2个专门由点组成的点向量用来存储特征点
//    detector.detect(img_1,keypoints_1);//将img_1图像中检测到的特征点存储起来放在keypoints_1中
//    detector.detect(img_2,keypoints_2);//同理
//    Mat img_keypoints_1,img_keypoints_2;
//    drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//在内存中画出特征点
//    drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
//    SiftDescriptorExtractor extractor;//定义描述子对象
//    Mat descriptors_1,descriptors_2;//存放特征向量的矩阵
//    extractor.compute(img_1,keypoints_1,descriptors_1);//计算特征向量
//    extractor.compute(img_2,keypoints_2,descriptors_2);
////    BruteForceMatcher<L2<float> > matcher;//定义一个burte force matcher对象
//    FlannBasedMatcher matcher;
//    vector<DMatch>matches;
//    matcher.match(descriptors_1,descriptors_2,matches);
/***************************方法3 orb****************************************/
//    OrbFeatureDetector detector;//构造函数采用内部默认的
//    std::vector<KeyPoint> keypoints_1,keypoints_2;//构造2个专门由点组成的点向量用来存储特征点
//    detector.detect(img_1,keypoints_1);//将img_1图像中检测到的特征点存储起来放在keypoints_1中
//    detector.detect(img_2,keypoints_2);//同理
//
//	printf("-- 目标图像特征点数 : %d \n", keypoints_1.size());
//
//    Mat img_keypoints_1,img_keypoints_2;
//    drawKeypoints(img_1,keypoints_1,img_keypoints_1,Scalar::all(-1),DrawMatchesFlags::DEFAULT);//在内存中画出特征点
//    drawKeypoints(img_2,keypoints_2,img_keypoints_2,Scalar::all(-1),DrawMatchesFlags::DEFAULT);
//    OrbDescriptorExtractor extractor;//定义描述子对象
//    Mat descriptors_1,descriptors_2;//存放特征向量的矩阵
//    extractor.compute(img_1,keypoints_1,descriptors_1);//计算特征向量
//    extractor.compute(img_2,keypoints_2,descriptors_2);
//    BruteForceMatcher<L2<float> > matcher;//定义一个burte force matcher对象
////    FlannBasedMatcher matcher; //can't use
//    vector<DMatch>matches;
//    matcher.match(descriptors_1,descriptors_2,matches);
/***************************orb****************************************/
    tm.stop();
    cout<<"time="<<tm.getTimeMilli()<<endl;
//    //绘制匹配线段
//    Mat img_matches;
//    drawMatches(img_1,keypoints_1,img_2,keypoints_2,matches,img_matches);//将匹配出来的结果放入内存img_matches中
//    //显示匹配线段
//    imshow("sift_Matches",img_matches);//显示的标题为Matches

//    imshow("sift_keypoints_1",img_keypoints_1);//显示特征点
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

	printf("-- 特征点匹配点数 : %d \n", keypoints_1.size());

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


    //img_2=imread("single2.jpg");
    //line( img_2, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 4 );
    //line( img_2, scene_corners[1], scene_corners[2], Scalar( 0, 255, 0), 4 );
    //line( img_2, scene_corners[2], scene_corners[3], Scalar( 0, 255, 0), 4 );
    //line( img_2, scene_corners[3], scene_corners[0], Scalar( 0, 255, 0), 4 );
    ////-- only show search image
    //imshow( "Object detection", img_2 );
    /**************************************************************************/
    waitKey(0);
    return 0;
}