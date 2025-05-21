#pragma once

#include "ifilter.hpp"

class GrayscaleFilter : public IFilter {
public:
    void apply(cv::Mat& image) override;
};
