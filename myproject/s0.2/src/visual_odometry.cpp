/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2016  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <opencv2/aruco.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <algorithm>
#include <boost/timer.hpp>

#include "myslam/config.h"
#include "myslam/visual_odometry.h"

namespace myslam {

    VisualOdometry::VisualOdometry() :
            state_(LOST), ref_(nullptr), curr_(nullptr), map_(new Map), num_lost_(0), num_inliers_(0) {
        num_of_features_ = Config::get<int>("number_of_features");
        scale_factor_ = Config::get<double>("scale_factor");
        level_pyramid_ = Config::get<int>("level_pyramid");
        match_ratio_ = Config::get<float>("match_ratio");
        max_num_lost_ = Config::get<float>("max_num_lost");
        min_inliers_ = Config::get<int>("min_inliers");
        key_frame_min_rot = Config::get<double>("keyframe_rotation");
        key_frame_min_trans = Config::get<double>("keyframe_translation");
        orb_ = cv::ORB::create(num_of_features_, scale_factor_, level_pyramid_);
    }

    VisualOdometry::~VisualOdometry() {

    }

    void VisualOdometry::mygetobjpoints() {

        objpoints.clear();
        for (int j = 0; j < charucoIds.size(); j++) {
            objpoints.push_back(
                    cv::Point3d(board.at<double>(8 * boardnum + j, 0), board.at<double>(8 * boardnum + j, 1),
                                board.at<double>(8 * boardnum + j, 2)));


        }

    }

    void VisualOdometry::mygetimgpoints() {
        imgpoints.clear();
        imgpoints = charucoCorners;
    }

    void VisualOdometry::charuco(cv::Mat image) {
        bool valid;

        cv::Mat imagecopy;
        image.copyTo(imagecopy);
        cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
                << 8.6911353168659366e+02, 0., 2.9267783375673446e+02, 0.,
                8.6721765725812759e+02, 2.9037435251520674e+02, 0., 0., 1.);
        cv::Mat distCoeffs = (cv::Mat_<double>(1, 5) << -1.0666525029122846e-01, 3.3794337314215589e-01,
                1.6656304800872223e-05, -3.7943927324066247e-03,
                4.9543475405042214e-01);

        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
        cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(3, 5, 0.055, 0.045, dictionary);
        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        cv::aruco::detectMarkers(image, dictionary, corners, ids);

        // if at least one marker detected
        if (ids.size() > 0) {
            std::vector<cv::Point2f> charucoCorners;
            std::vector<int> charucoIds;
            int boardnum;
            int i;
            for (boardnum = 0; boardnum < 3; boardnum++) {
                for (i = 0; i < 7; i++) {
                    board->ids.erase(board->ids.begin());

                    board->ids.push_back(i + 7 * boardnum);
                }
                cv::aruco::interpolateCornersCharuco(corners, ids, image, board, charucoCorners, charucoIds,
                                                     cameraMatrix, distCoeffs);
                if (charucoIds.size() > 3) {

                    //保存charucoids（boardnum）
                    //保存objcorne
                    //保存imgcorner
                    mysaveboi(boardnum, charucoCorners, charucoIds);
                    //计算pnp更改T_c_w,将tvec和rvec保存
                    Mat rvec, tvec, inliers;
                    cv::solvePnPRansac( objpoints, imgpoints, cameraMatrix, Mat(), rvec, tvec, false, 100, 4.0, 0.99, inliers );
                    T_c_r_estimated_ = SE3(
                            SO3(rvec.at<double>(0, 0), rvec.at<double>(1, 0), rvec.at<double>(2, 0)),
                            Vector3d(tvec.at<double>(0, 0), tvec.at<double>(1, 0), tvec.at<double>(2, 0))
                    );
                    SO3 SO3R(rvec.at<double>(0, 0), rvec.at<double>(1, 0), rvec.at<double>(2, 0));
                    std::cout <<"rvec:"<< rvec << std::endl;
                    std::cout <<"tcw:"<< SO3R<< std::endl;
                    state_ = 1;
                }
            }
        } else {
            state_ = 0;
            //std::cout<<"lost"<<std::endl;
        }

    }

    void
    VisualOdometry::mysaveboi(int _boardnum, std::vector<cv::Point2f> _charucoCorners, std::vector<int> _charucoIds) {
        boardnum = _boardnum;
        charucoCorners = _charucoCorners;
        charucoIds = _charucoIds;
        mygetimgpoints();
        mygetobjpoints();

    }

    bool VisualOdometry::addFrame(Frame::Ptr frame) {
        // std::cout<<"s:"<<std::endl;
        // std::cout<<state_<<std::endl;
        switch (state_) {
            case 1: {
                //std::cout<<"11"<<std::endl;
                frame->T_c_w_ = T_c_r_estimated_;
                // std::cout<<"11"<<std::endl;
                //保存objcorner
                //保存imgcorner
                //计算pnp更改T_c_w,将tvec和rvec保存
                //保存charucoids（boardnum）
                //保存camera ids
                break;
            }
            default:
                break;

        }
        return true;
    }

    void VisualOdometry::extractKeyPoints() {
        orb_->detect(curr_->color_, keypoints_curr_);
    }

    void VisualOdometry::computeDescriptors() {
        //compute (in,(out in-out),out)
        orb_->compute(curr_->color_, keypoints_curr_, descriptors_curr_);
    }

    void VisualOdometry::featureMatching() {
        // match desp_ref and desp_curr, use OpenCV's brute force match
        vector<cv::DMatch> matches;
        cv::BFMatcher matcher(cv::NORM_HAMMING);
        matcher.match(descriptors_ref_, descriptors_curr_, matches);
        // select the best matches
        float min_dis = std::min_element(
                matches.begin(), matches.end(),
                [](const cv::DMatch &m1, const cv::DMatch &m2) {
                    return m1.distance < m2.distance;
                })->distance;

        feature_matches_.clear();
        for (cv::DMatch &m : matches) {
            if (m.distance < max<float>(min_dis * match_ratio_, 30.0)) {
                feature_matches_.push_back(m);
            }
        }
        cout << "good matches: " << feature_matches_.size() << endl;
    }

    void VisualOdometry::setRef3DPoints() {
        // select the features with depth measurements
        pts_3d_ref_.clear();
        descriptors_ref_ = Mat();
        for (size_t i = 0; i < keypoints_curr_.size(); i++) {
            double d = ref_->findDepth(keypoints_curr_[i]);
            if (d > 0) {
                Vector3d p_cam = ref_->camera_->pixel2camera(
                        Vector2d(keypoints_curr_[i].pt.x, keypoints_curr_[i].pt.y), d
                );
                pts_3d_ref_.push_back(cv::Point3f(p_cam(0, 0), p_cam(1, 0), p_cam(2, 0)));
                descriptors_ref_.push_back(descriptors_curr_.row(i));
            }
        }
    }

    void VisualOdometry::poseEstimationPnP() {
        // construct the 3d 2d observations
        vector<cv::Point3f> pts3d;
        vector<cv::Point2f> pts2d;

        for (cv::DMatch m:feature_matches_) {
            pts3d.push_back(pts_3d_ref_[m.queryIdx]);
            pts2d.push_back(keypoints_curr_[m.trainIdx].pt);
        }

        Mat K = (cv::Mat_<double>(3, 3) <<
                                        ref_->camera_->fx_, 0, ref_->camera_->cx_,
                0, ref_->camera_->fy_, ref_->camera_->cy_,
                0, 0, 1
        );
        Mat rvec, tvec, inliers;
        cv::solvePnPRansac(pts3d, pts2d, K, Mat(), rvec, tvec, false, 100, 4.0, 0.99, inliers);
        num_inliers_ = inliers.rows;
        cout << "pnp inliers: " << num_inliers_ << endl;
        T_c_r_estimated_ = SE3(
                SO3(rvec.at<double>(0, 0), rvec.at<double>(1, 0), rvec.at<double>(2, 0)),
                Vector3d(tvec.at<double>(0, 0), tvec.at<double>(1, 0), tvec.at<double>(2, 0))
        );
    }

    bool VisualOdometry::checkEstimatedPose() {
        // check if the estimated pose is good
        if (num_inliers_ < min_inliers_) {
            cout << "reject because inlier is too small: " << num_inliers_ << endl;
            return false;
        }
        // if the motion is too large, it is probably wrong
        Sophus::Vector6d d = T_c_r_estimated_.log();
        if (d.norm() > 5.0) {
            cout << "reject because motion is too large: " << d.norm() << endl;
            return false;
        }
        return true;
    }

    bool VisualOdometry::checkKeyFrame() {
        Sophus::Vector6d d = T_c_r_estimated_.log();
        Vector3d trans = d.head<3>();
        Vector3d rot = d.tail<3>();
        if (rot.norm() > key_frame_min_rot || trans.norm() > key_frame_min_trans)
            return true;
        return false;
    }

    void VisualOdometry::addKeyFrame() {
        cout << "adding a key-frame" << endl;
        map_->insertKeyFrame(curr_);
    }

}