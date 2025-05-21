#pragma once

#include <opencv2/opencv.hpp>

class IFilter {
public:
    virtual void apply(cv::Mat& image) = 0;
    virtual ~IFilter() = default;
};
