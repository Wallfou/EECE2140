#include "../include/Image.h"
#include <fstream>
#include <iostream>
#include <cmath>

Image::Image() : rows(0), cols(0) {}

Image::Image(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows, std::vector<int>(cols, 0));
}

Image::Image(const std::vector<std::vector<int>>& matrix) {
    data = matrix;
    rows = matrix.size();
    cols = (rows > 0) ? matrix[0].size() : 0;
}

int Image::clamp(int value) const {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

bool Image::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    if (!(file >> rows >> cols)) {
        std::cerr << "Error: Invalid file format (missing dimensions)" << std::endl;
        return false;
    }

    if (rows <= 0 || cols <= 0) {
        std::cerr << "Error: Invalid dimensions (" << rows << "x" << cols << ")" << std::endl;
        return false;
    }

    data.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(file >> data[i][j])) {
                std::cerr << "Error: Insufficient pixel data" << std::endl;
                return false;
            }
            data[i][j] = clamp(data[i][j]);
        }
    }
    file.close();
    return true;
}

bool Image::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return false;
    }

    file << rows << " " << cols << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file << data[i][j];
            if (j < cols - 1) file << " ";
        }
        file << std::endl;
    }
    file.close();
    return true;
}

int Image::getPixel(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return 0;
    }
    return data[row][col];
}

void Image::setPixel(int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = clamp(value);
    }
}

void Image::setData(const std::vector<std::vector<int>>& newData) {
    data = newData;
    rows = newData.size();
    cols = (rows > 0) ? newData[0].size() : 0;
}

double Image::getMean() const {
    if (rows == 0 || cols == 0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += data[i][j];
        }
    }
    return sum / (rows * cols);
}

double Image::getStdDev() const {
    if (rows == 0 || cols == 0) return 0.0;
    
    double mean = getMean();
    double sumSquaredDiff = 0.0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double diff = data[i][j] - mean;
            sumSquaredDiff += diff * diff;
        }
    }
    return std::sqrt(sumSquaredDiff / (rows * cols));
}

void Image::printStatistics() const {
    std::cout << "Image Statistics:" << std::endl;
    std::cout << "  Dimensions: " << rows << "x" << cols << std::endl;
    std::cout << "  Mean: " << getMean() << std::endl;
    std::cout << "  Std Dev: " << getStdDev() << std::endl;
}

bool Image::isValid() const {
    return (rows > 0 && cols > 0 && data.size() == static_cast<size_t>(rows));
}
