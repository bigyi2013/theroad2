#include <opencv2/aruco/charuco.hpp>
#include<opencv2/opencv.hpp>

int main()
{
cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(3,5, 0.05, 0.04, dictionary);
cv::Mat boardImage; 
int i;
for (i=0;i<7;i++)
{
board->ids.erase(board->ids.begin());
board->ids.push_back(i+0);
}
 for(i =0;i<board->ids.size();i++)
 {
   std::cout<<board->ids[i]<<std::endl;
 }
board->draw( cv::Size(500, 600), boardImage, 10, 1 );
cv::imshow("img",boardImage);
cv::imwrite("img.bmp",boardImage);
cv::waitKey(0);
return 0;
}
