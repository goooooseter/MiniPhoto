#include "blurfilter.hpp"

void BlurFilter::apply(cv::Mat& image) {
    cv::GaussianBlur(image, image, cv::Size(kernelSize, kernelSize), 0);
}
