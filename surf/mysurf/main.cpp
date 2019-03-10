#include "mysurf.h"
#include "stdio.h"
#include "conio.h"
#include <stdio.h>
#include <iostream>
using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;
void main(){
	Mat img_object = imread(argv[1], IMREAD_GRAYSCALE);
	Mat img_scene = imread(argv[2], IMREAD_GRAYSCALE);
	return 0;
}
