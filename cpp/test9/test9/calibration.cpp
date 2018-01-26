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
	src = imread("3.jpg",1);
	//imshow(window_name, src);
	Size patternsize(12,13); //interior number of corners
	vector<Point2f> corners; //this will be filled by the detected corners
							 //CALIB_CB_FAST_CHECK saves a lot of time on images
							 //that do not contain any chessboard corners
	bool patternfound = findChessboardCorners(src, patternsize, corners,
		CALIB_CB_ADAPTIVE_THRESH);
	if (patternfound) 
		cornerSubPix(src, corners, Size(11, 11), Size(-1, -1),
			TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
	drawChessboardCorners( src, patternsize, Mat(corners), patternfound);
	imshow(window_name, src);
	waitKey(0);
	return 0;
}
