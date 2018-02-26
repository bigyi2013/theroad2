#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <Windows.h>

using namespace std;
using namespace cv;

//����ȫ�ֱ���
Mat srcImage, grayImage;
int thresh = 100;
const int threshMaxValue = 255;
RNG rng(12345);

//�����ص�����
void thresh_callback(int, void*);

int main()
{
	srcImage = imread("0.jpg");

	//�ж��ļ��Ƿ���سɹ�
	if (!srcImage.data)
	{
		cout << "ͼ�����ʧ��...";
		return -1;
	}
	else
		cout << "ͼ����سɹ�..." << endl << endl;

	namedWindow("ԭͼ��", WINDOW_AUTOSIZE);
	imshow("ԭͼ��", srcImage);

	//ͼ��ת��Ϊ�Ҷ�ͼ��ƽ��
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	blur(grayImage, grayImage, Size(3, 3));

	namedWindow("�Ҷ�ͼ", WINDOW_AUTOSIZE);
	imshow("�Ҷ�ͼ", grayImage);

	//�����켣��
	createTrackbar("Thresh:", "�Ҷ�ͼ", &thresh, threshMaxValue, thresh_callback);
	thresh_callback(thresh, 0);
	waitKey(0);

	return 0;
}

void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	//canny��Ե���
	Canny(grayImage, canny_output, thresh, thresh * 2, 3);
	//������ȡ
	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Draw contours and find biggest contour (if there are other contours in the image, we assume the biggest one is the desired rect)
	// drawing here is only for demonstration!
	int biggestContourIdx = -1;
	float biggestContourArea = 0;
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 100, 0);
		drawContours(drawing, contours, i, color, 1, 8, hierarchy, 0, cv::Point());

		float ctArea = cv::contourArea(contours[i]);
		if (ctArea > biggestContourArea)
		{
			biggestContourArea = ctArea;
			biggestContourIdx = i;
		}
	}


	// compute the rotated bounding rect of the biggest contour! (this is the part that does what you want/need)
	cv::RotatedRect boundingBox = cv::minAreaRect(contours[biggestContourIdx]);
	// one thing to remark: this will compute the OUTER boundary box, so maybe you have to erode/dilate if you want something between the ragged lines



	// draw the rotated rect
	cv::Point2f corners[5];
	boundingBox.points(corners);
	cv::line(drawing, corners[0], corners[1], cv::Scalar(255, 255, 255));
	cv::line(drawing, corners[1], corners[2], cv::Scalar(255, 255, 255));
	cv::line(drawing, corners[2], corners[3], cv::Scalar(255, 255, 255));
	cv::line(drawing, corners[3], corners[0], cv::Scalar(255, 255, 255));
	corners[4] = corners[0] + corners[1] + corners[2] + corners[3];
	corners[4].x = (corners[4].x) / 4;
	corners[4].y = (corners[4].y) / 4;
	cv::circle(drawing, corners[4], 2, cv::Scalar(255, 255, 255));


	//����ͼ���
	vector<Moments>mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}

	//����ͼ�������
	vector<Point2f>mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}


	namedWindow("����ͼ", WINDOW_AUTOSIZE);
	imshow("����ͼ", drawing);

	//��moments�ؼ����������������opencv�������������бȽ�
	printf("\t Info: Area and Contour Length \n");
	for (int i = 0; i < contours.size(); i++)
	{
		printf("* Contour[%d] - Area(M_00)=%.2f-Area OpenCV:%.2f - Length:%.2f\n", i, mu[i].m00, contourArea(contours[i]), arcLength(contours[i], true));
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		circle(drawing, mc[i], 4, color, -1, 8, 0);
	}
}