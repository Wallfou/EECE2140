#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

    int clamp(int value) const;

public:
    Image();
    Image(int rows, int cols);
    Image(const std::vector<std::vector<int>>& matrix);

    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getPixel(int row, int col) const;
    const std::vector<std::vector<int>>& getData() const { return data; }
    void setPixel(int row, int col, int value);
    void setData(const std::vector<std::vector<int>>& newData);
    double getMean() const;
    double getStdDev() const;
    void printStatistics() const;

    bool isValid() const;
};

#endif
