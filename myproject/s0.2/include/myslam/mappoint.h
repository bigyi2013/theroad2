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

#ifndef MAPPOINT_H
#define MAPPOINT_H

namespace myslam {

    class Frame;

    class MapPoint {
    public:
        typedef shared_ptr<MapPoint> Ptr;
        unsigned long id_; // ID
        Vector3d pos_;       // Position in world
        Vector3d norm_;      // Normal of viewing direction
        Mat descriptor_; // Descriptor for matching
        int observed_times_;    // being observed by feature matching algo.
        int matched_times_;     // being an inliner in pose estimation
        int boardnum;
        vector<cv::Point3f> objpoints;
        vector<cv::Point2f> imgpoints;
        std::vector<int> charucoIds;
        std::vector<cv::Point2f> charucoCorners;
        double boardsize = 0.055;
        cv::Mat board = (cv::Mat_<double>(24, 3) << boardsize, boardsize, 0, 2 * boardsize, boardsize, 0, boardsize, 2 *
                                                                                                                     boardsize, 0,
                2 * boardsize, 2 * boardsize, 0, boardsize, 3 * boardsize, 0, 2 * boardsize, 3 *
                                                                                             boardsize, 0, boardsize,
                4 * boardsize, 0, 2 * boardsize, 4 * boardsize, 0,
                boardsize, boardsize, 0, 2 * boardsize, boardsize, 0, boardsize, 2 * boardsize, 0, 2 * boardsize, 2 *
                                                                                                                  boardsize, 0, boardsize,
                3 * boardsize, 0, 2 * boardsize, 3 * boardsize, 0, boardsize, 4 * boardsize, 0, 2 * boardsize, 4 *
                                                                                                               boardsize, 0,
                boardsize, boardsize, 0, 2 * boardsize, boardsize, 0, boardsize, 2 * boardsize, 0, 2 * boardsize, 2 *
                                                                                                                  boardsize, 0, boardsize,
                3 * boardsize, 0, 2 * boardsize, 3 * boardsize, 0, boardsize, 4 * boardsize, 0, 2 * boardsize, 4 *
                                                                                                               boardsize, 0);

        //cv::Mat<double, 8, 3> board2=(boardsize,boardsize,0,2*boardsize,boardsize,0,boardsize,2*boardsize,0,2*boardsize,2*boardsize,0,boardsize,3*boardsize,0,2*boardsize,3*boardsize,0,boardsize,4*boardsize,0,2*boardsize,4*boardsize,0);
        //cv::Mat<double, 8, 3> board3=(boardsize,boardsize,0,2*boardsize,boardsize,0,boardsize,2*boardsize,0,2*boardsize,2*boardsize,0,boardsize,3*boardsize,0,2*boardsize,3*boardsize,0,boardsize,4*boardsize,0,2*boardsize,4*boardsize,0);
        MapPoint();

        MapPoint(long id, Vector3d position, Vector3d norm);

        mygetobjpoints();

        mygetimgpoints();

        // factory function
        static MapPoint::Ptr createMapPoint();
    };
}

#endif // MAPPOINT_H
