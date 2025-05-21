#pragma once

#include "ifilter.hpp"

class BlurFilter : public IFilter {
private:
    int kernelSize;
public:
    BlurFilter(int k = 5) : kernelSize(k | 1) {}
    void apply(cv::Mat& image) override;
};
