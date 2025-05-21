#pragma once

#include "ifilter.hpp"

class BrightnessFilter : public IFilter {
private:
    int delta;
public:
    BrightnessFilter(int d) : delta(d) {}
    void apply(cv::Mat& image) override;
};
