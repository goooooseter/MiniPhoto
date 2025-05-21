#include "image.hpp"

bool Image::load(const std::string& path) {
    data = cv::imread(path);
    return !data.empty();
}

bool Image::save(const std::string& path) const {
    return cv::imwrite(path, data);
}

cv::Mat& Image::getData() {
    return data;
}
