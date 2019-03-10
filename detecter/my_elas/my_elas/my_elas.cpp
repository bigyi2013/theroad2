// my_elas.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "elas.h"
#include "image.h"
#include <minmax.h>

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;
using namespace std;
// compute disparities of pgm image input pair file_1, file_2
void process(const char* file_1, const char* file_2) {

	cout << "Processing: " << file_1 << ", " << file_2 << endl;

	// load images
	image<uchar> *I1, *I2;
	I1 = loadPGM(file_1);
	I2 = loadPGM(file_2);

	// check for correct size
	if (I1->width() <= 0 || I1->height() <= 0 || I2->width() <= 0 || I2->height() <= 0 ||
		I1->width() != I2->width() || I1->height() != I2->height()) {
		cout << "ERROR: Images must be of same size, but" << endl;
		cout << "       I1: " << I1->width() << " x " << I1->height() <<
			", I2: " << I2->width() << " x " << I2->height() << endl;
		delete I1;
		delete I2;
		return;
	}

	// get image width and height
	int32_t width = I1->width();
	int32_t height = I1->height();

	// allocate memory for disparity images
	const int32_t dims[3] = { width,height,width }; // bytes per line = width
	float* D1_data = (float*)malloc(width*height * sizeof(float));
	float* D2_data = (float*)malloc(width*height * sizeof(float));

	// process
	Elas::parameters param;
	param.postprocess_only_left = false;
	Elas elas(param);
	elas.process(I1->data, I2->data, D1_data, D2_data, dims);
	// find maximum disparity for scaling output disparity images to [0..255]
	float disp_max = 0;
	for (int32_t i = 0; i<width*height; i++) {
		if (D1_data[i]>disp_max) disp_max = D1_data[i];
		if (D2_data[i]>disp_max) disp_max = D2_data[i];
	}

	// copy float to uchar
	image<uchar> *D1 = new image<uchar>(width, height);
	image<uchar> *D2 = new image<uchar>(width, height);
	for (int32_t i = 0; i<width*height; i++) {
		D1->data[i] = (uint8_t)max(255.0*D1_data[i] / disp_max, 0.0);
		D2->data[i] = (uint8_t)max(255.0*D2_data[i] / disp_max, 0.0);
	}

	// save disparity images
	char output_1[1024];
	char output_2[1024];
	strncpy_s(output_1, file_1, strlen(file_1) - 4);
	strncpy_s(output_2, file_2, strlen(file_2) - 4);
	output_1[strlen(file_1) - 4] = '\0';
	output_2[strlen(file_2) - 4] = '\0';
	strcat_s(output_1, "_disp.pgm");
	strcat_s(output_2, "_disp.pgm");
	savePGM(D1, output_1);
	savePGM(D2, output_2);

	// free memory
	delete I1;
	delete I2;
	delete D1;
	delete D2;
	free(D1_data);
	free(D2_data);

// draw the support point on raw png image.
	/*cout << " number of support point " << elas.p_support.size() << endl;
	Mat srcl, srcr;
	srcl = imread("../img/l88.png");
	if (srcl.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		return ;
	}
	RNG rng(12345);
	Point support_pt;
	for (size_t i = 0; i < elas.p_support.size(); i++)
	{
		support_pt = Point(elas.p_support[i].u, elas.p_support[i].v);
		circle(srcl, support_pt, 2, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), -1, 8, 0);
	}
	imshow("imagel", srcl);
	imwrite("result88.png",srcl);
	waitKey(0);*/
}

int main()
{
	process("../img/l88.pgm", "../img/r88.pgm");
	//process("../img/l20.pgm", "../img/r20.pgm");
	//process("../img/l85.pgm", "../img/r85.pgm");
	//process("../img/l88.pgm", "../img/r88.pgm");
	cout << "... done!" << endl;
	system("pause");
    return 0;
}

