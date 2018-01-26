// opencvtest.cpp: 定义控制台应用程序的入口点。
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp> 
#include "stdafx.h"
//using namespace std;
//int main()
//{
//	IplImage * test;
//	test = cvLoadImage("C:\\theroad\\opencv\\1.jpg");//图片路径
//	cvNamedWindow("test_demo", 1);
//	cvShowImage("test_demo", test);
//	cvWaitKey(0);
//	cvDestroyWindow("test_demo");
//	cvReleaseImage(&test);
//	return 0;
//}
#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  


using namespace cv;


int main()
{
	// 读入一张图片（游戏原画）  
	Mat img = imread("C:\\theroad\\opencv\\1.jpg");
	// 创建一个名为 "游戏原画"窗口  
	namedWindow("游戏原画");
	// 在窗口中显示游戏原画  
	imshow("游戏原画", img);
	// 等待6000 ms后窗口自动关闭  
	waitKey(6000);
}