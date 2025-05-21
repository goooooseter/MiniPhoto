#include "grayscalefilter.hpp"

void GrayscaleFilter::apply(cv::Mat& image) {
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
}
