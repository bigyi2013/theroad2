int main(int argc, char const *argv[])
{
	Mat img_object = imread(argv[1], IMREAD_GRAYSCALE);
	Mat img_scene = imread(argv[2], IMREAD_GRAYSCALE);
	//-- Step 1: Detect the keypoints and extract descriptors using SURF
	int minHessian = 800;
	Ptr<SURF> detector = SURF::create(minHessian, 4,3, false, false);
	std::vector<KeyPoint> keypoints_object, keypoints_scene;
	Mat descriptors_object, descriptors_scene;
	detector->detectAndCompute(img_object, Mat(), keypoints_object, descriptors_object);
	detector->detectAndCompute(img_scene, Mat(), keypoints_scene, descriptors_scene);
	//-- Step 2: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match(descriptors_object, descriptors_scene, matches);
	double max_dist = 0; double min_dist = 100;
	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_object.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}
	//printf("-- Max dist : %f \n", max_dist);
	//printf("-- Min dist : %f \n", min_dist);
		//-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
	std::vector< DMatch > good_matches;
	for (int i = 0; i < descriptors_object.rows; i++)
	{
		if (matches[i].distance < 3 * min_dist)
		{
			good_matches.push_back(matches[i]);
		}
	}
	Mat img_matches;
	//drawMatches(img_object, keypoints_object, img_scene, keypoints_scene,
	//	good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
	//	std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//-- Localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < good_matches.size(); i++)
	{
		//-- Get the keypoints from the good matches
		obj.push_back(keypoints_object[good_matches[i].queryIdx].pt);
		scene.push_back(keypoints_scene[good_matches[i].trainIdx].pt);
	}
	Mat H = findHomography(obj, scene, RANSAC,3,noArray(),2000,0.995);
	std::cout << "H����" << std::endl;
	std::cout << H << std::endl;
	//-- Get the corners from the image_1 ( the object to be "detected" )
	std::vector<Point2f> obj_corners(4);
	obj_corners[0] = cvPoint(0, 0); obj_corners[1] = cvPoint(img_object.cols, 0);
	obj_corners[2] = cvPoint(img_object.cols, img_object.rows); obj_corners[3] = cvPoint(0, img_object.rows);
	std::vector<Point2f> scene_corners(4);
	perspectiveTransform(obj_corners, scene_corners, H);
	return 0;
}