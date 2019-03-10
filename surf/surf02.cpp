@@ -18,6 +18,7 @@ const float inlier_threshold = 2.5f; // Distance threshold to identify inliers
const float nn_match_ratio = 0.8f;   // Nearest neighbor matching ratio
int main(int argc, char* argv[])
{

	CommandLineParser parser(argc, argv,
		"{@img1 | ../data/graf1.png | input image 1}"
		"{@img2 | ../data/graf3.png | input image 2}"
@ -78,6 +79,17 @@ int main(int argc, char* argv[])
	std::cout << homography << std::endl;
	std::cout << "H2����" << std::endl;
	std::cout << homography2 << std::endl;
	//�ֽⵥӦ�Ծ���
	cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
		<< 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
		8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
	cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -1.0666525029122846e-01, 3.3794337314215589e-01,
		1.6656304800872223e-05, -3.7943927324066247e-03,
		4.9543475405042214e-01);
	vector<Mat> Rs_decomp, ts_decomp, normals_decomp;
	int solutions = decomposeHomographyMat(homography, cameraMatrix, Rs_decomp, ts_decomp, normals_decomp);

	//�ֽⵥӦ�Ծ������
	drawMatches(img1, inliers1, img2, inliers2, good_matches, result);
	imwrite("result.png", result);
	//����start
@ -99,6 +111,8 @@ int main(int argc, char* argv[])
	cout << "*******************************" << endl;
	cout << "# Keypoints 1:                        \t" << kpts1.size() << endl;
	cout << "# Keypoints 2:                        \t" << kpts2.size() << endl;
	cout << "# r:                        \t" << Rs_decomp[0]<< endl;
	cout << "# t:                        \t" <<ts_decomp[0] << endl;
	cout << "# Matches��ƥ��㣩:                            \t" << matched1.size() << endl;
	cout << "# Inliers����ȷƥ��㣩:                            \t" << inliers1.size() << endl;
	cout << "# Inliers Ratio�����Ŷȣ�:                      \t" << inlier_ratio << endl;