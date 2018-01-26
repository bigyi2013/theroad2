#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat src; Mat dst;
using namespace cv;
char window_name[] = "board";
int main(void)
{
	namedWindow(window_name, WINDOW_AUTOSIZE);
	src = imread("3.jpg", 1);

	imshow(window_name, src);
	waitKey(0);
	return 0;
}
