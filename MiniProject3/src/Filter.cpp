#include "../include/Filter.h"
#include <algorithm>
#include <iostream>

Filter::Filter(BorderPolicy policy) : borderPolicy(policy) {}

int Filter::getPixelWithBorder(const Image& img, int row, int col) const {
    int rows = img.getRows();
    int cols = img.getCols();
    
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        switch (borderPolicy) {
            case BorderPolicy::CLAMP:
                row = std::max(0, std::min(row, rows - 1));
                col = std::max(0, std::min(col, cols - 1));
                return img.getPixel(row, col);
                
            case BorderPolicy::ZERO_PADDING:
                return 0;
                
            case BorderPolicy::IGNORE_BORDERS:
                return 0;
        }
    }
    
    return img.getPixel(row, col);
}

std::vector<int> Filter::getNeighborhood(const Image& img, int row, int col) const {
    std::vector<int> neighborhood;
    neighborhood.reserve(9);
    
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int r = row + dr;
            int c = col + dc;
            neighborhood.push_back(getPixelWithBorder(img, r, c));
        }
    }
    
    return neighborhood;
}

int Filter::applyMeanFilter(const std::vector<int>& neighborhood) const {
    int sum = 0;
    for (int value : neighborhood) {
        sum += value;
    }
    return sum / neighborhood.size();
}

int Filter::applyMedianFilter(const std::vector<int>& neighborhood) const {
    std::vector<int> sorted = neighborhood;
    std::sort(sorted.begin(), sorted.end());
    return sorted[sorted.size() / 2];
}

Image Filter::applyFilter(const Image& input, FilterType type, int iterations) const {
    if (!input.isValid()) {
        std::cerr << "Error: Invalid input image" << std::endl;
        return input;
    }
    
    Image result = input;
    
    for (int iter = 0; iter < iterations; iter++) {
        Image temp(result.getRows(), result.getCols());
        
        int startRow = 0, endRow = result.getRows();
        int startCol = 0, endCol = result.getCols();
        
        if (borderPolicy == BorderPolicy::IGNORE_BORDERS) {
            startRow = 1;
            endRow = result.getRows() - 1;
            startCol = 1;
            endCol = result.getCols() - 1;
            for (int i = 0; i < result.getRows(); i++) {
                for (int j = 0; j < result.getCols(); j++) {
                    if (i == 0 || i == result.getRows() - 1 || 
                        j == 0 || j == result.getCols() - 1) {
                        temp.setPixel(i, j, result.getPixel(i, j));
                    }
                }
            }
        }
        
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                std::vector<int> neighborhood = getNeighborhood(result, i, j);
                
                int newValue;
                switch (type) {
                    case FilterType::MEAN:
                        newValue = applyMeanFilter(neighborhood);
                        break;
                    case FilterType::MEDIAN:
                        newValue = applyMedianFilter(neighborhood);
                        break;
                    default:
                        newValue = result.getPixel(i, j);
                }
                
                temp.setPixel(i, j, newValue);
            }
        }
        
        result = temp;
    }
    
    return result;
}

void Filter::setBorderPolicy(BorderPolicy policy) {
    borderPolicy = policy;
}

FilterType Filter::parseFilterType(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    
    if (lower == "mean" || lower == "average") {
        return FilterType::MEAN;
    } else if (lower == "median") {
        return FilterType::MEDIAN;
    } else {
        std::cerr << "Warning: Unknown filter type '" << str 
                  << "', defaulting to mean" << std::endl;
        return FilterType::MEAN;
    }
}

BorderPolicy Filter::parseBorderPolicy(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    
    if (lower == "clamp" || lower == "replicate") {
        return BorderPolicy::CLAMP;
    } else if (lower == "zero" || lower == "zero_padding") {
        return BorderPolicy::ZERO_PADDING;
    } else if (lower == "ignore" || lower == "ignore_borders") {
        return BorderPolicy::IGNORE_BORDERS;
    } else {
        std::cerr << "Warning: Unknown border policy '" << str 
                  << "', defaulting to clamp" << std::endl;
        return BorderPolicy::CLAMP;
    }
}
