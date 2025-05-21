#pragma once

#include <string>
#include <opencv2/opencv.hpp>

class Image {
private:
    cv::Mat data;
public:
    bool load(const std::string& path);
    bool save(const std::string& path) const;
    cv::Mat& getData();
};
