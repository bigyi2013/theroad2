#pragma once
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
class mysurf
{
public:

	float match_size(Mat img_object, Mat img_scene);
	float getR();
private:
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
};
