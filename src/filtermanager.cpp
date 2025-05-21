#include "filtermanager.hpp"

void FilterManager::addFilter(std::unique_ptr<IFilter> filter) {
    filters.push_back(std::move(filter));
}

void FilterManager::applyAll(cv::Mat& image) {
    for (auto& filter : filters)
        filter->apply(image);
}

void FilterManager::clear() {
    filters.clear();
}
