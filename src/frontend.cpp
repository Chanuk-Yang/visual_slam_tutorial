//
// Created by gaoxiang on 19-5-2.
//

#include <opencv2/opencv.hpp>

#include "myslam/algorithm.h"
#include "myslam/backend.h"
#include "myslam/config.h"
#include "myslam/feature.h"
#include "myslam/frontend.h"
#include "myslam/g2o_types.h"
#include "myslam/map.h"
#include "myslam/viewer.h"

namespace myslam {

Frontend::Frontend() {

}

bool Frontend::AddFrame(myslam::Frame::Ptr frame) {
    current_frame_ = frame;

    switch (status_) {
        case FrontendStatus::INITING:
            StereoInit();
            // break;
        case FrontendStatus::TRACKING_GOOD:
        case FrontendStatus::TRACKING_BAD:
            // Track();
            break;
        case FrontendStatus::LOST:
            // Reset();
            break;
    }

    last_frame_ = current_frame_;
    return true;
}

bool Frontend::StereoInit() {

    if (viewer_) {
        viewer_->AddCurrentFrame(current_frame_);
        // viewer_->UpdateMap();
    }
    return false;
}


bool Frontend::Reset() {
    LOG(INFO) << "Reset is not implemented. ";
    return false;
}

}  // namespace myslam