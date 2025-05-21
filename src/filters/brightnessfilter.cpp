#include "brightnessfilter.hpp"

void BrightnessFilter::apply(cv::Mat& image) {
    image.convertTo(image, -1, 1, delta);
}
