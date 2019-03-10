// surf3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
int main()
{
	Mat img_object = imread("../image.jpg", IMREAD_GRAYSCALE);
	Mat img_scene = imread("../image1.jpg", IMREAD_GRAYSCALE);

	mysurf a;
	float matchsize = a.match_size(img_object, img_scene);
	cout << "match point number:"  << matchsize << endl;
	float r = a.getR();
	cout << "xuan zhuan jiao du:" << r << endl;
	system("pause");
    return 0;
}

