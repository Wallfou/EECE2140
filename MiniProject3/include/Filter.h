#ifndef FILTER_H
#define FILTER_H

#include "Image.h"
#include <string>

enum class BorderPolicy {
    CLAMP,
    ZERO_PADDING,
    IGNORE_BORDERS
};

enum class FilterType {
    MEAN,
    MEDIAN
};

class Filter {
private:
    BorderPolicy borderPolicy;
    int getPixelWithBorder(const Image& img, int row, int col) const;
    std::vector<int> getNeighborhood(const Image& img, int row, int col) const;
    int applyMeanFilter(const std::vector<int>& neighborhood) const;
    int applyMedianFilter(const std::vector<int>& neighborhood) const;

public:
    Filter(BorderPolicy policy = BorderPolicy::CLAMP);
    Image applyFilter(const Image& input, FilterType type, int iterations = 1) const;
    void setBorderPolicy(BorderPolicy policy);
    BorderPolicy getBorderPolicy() const { return borderPolicy; }
    static FilterType parseFilterType(const std::string& str);
    static BorderPolicy parseBorderPolicy(const std::string& str);
};

#endif
