#pragma once

#include <vector>
#include <memory>
#include "filters/ifilter.hpp"

class FilterManager {
private:
    std::vector<std::unique_ptr<IFilter>> filters;
public:
    void addFilter(std::unique_ptr<IFilter> filter);
    void applyAll(cv::Mat& image);
    void clear();
};
