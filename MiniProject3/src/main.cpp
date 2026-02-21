#include "../include/Image.h"
#include "../include/Filter.h"
#include <iostream>
#include <string>

void printUsage() {
    std::cout << "Usage: denoise <input> <output> <filter> [iterations] [border]\n";
    std::cout << "Examples:\n";
    std::cout << "  denoise noisy.txt clean.txt mean\n";
    std::cout << "  denoise noisy.txt clean.txt median 2\n";
    std::cout << "  denoise noisy.txt clean.txt mean 3 zero\n";
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Error: Insufficient arguments\n";
        printUsage();
        return 1;
    }
    
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string filterTypeStr = argv[3];
    
    int iterations = 1;
    if (argc >= 5) {
        try {
            iterations = std::stoi(argv[4]);
            if (iterations < 1) {
                std::cerr << "Error: Iterations must be at least 1\n";
                return 1;
            }
        } catch (...) {
            std::cerr << "Error: Invalid iterations value\n";
            return 1;
        }
    }
    
    BorderPolicy borderPolicy = BorderPolicy::CLAMP;
    if (argc >= 6) {
        borderPolicy = Filter::parseBorderPolicy(argv[5]);
    }
    
    Image inputImage;
    if (!inputImage.loadFromFile(inputFile)) {
        return 1;
    }
    
    std::cout << "\nBefore denoising:\n";
    inputImage.printStatistics();
    
    FilterType filterType = Filter::parseFilterType(filterTypeStr);
    Filter filter(borderPolicy);
    
    Image outputImage = filter.applyFilter(inputImage, filterType, iterations);
    
    std::cout << "\nAfter denoising:\n";
    outputImage.printStatistics();
    
    double stdDevBefore = inputImage.getStdDev();
    double stdDevAfter = outputImage.getStdDev();
    
    std::cout << "\nNoise reduction: " 
              << ((stdDevBefore - stdDevAfter) / stdDevBefore * 100.0) 
              << "%\n";
    
    if (!outputImage.saveToFile(outputFile)) {
        return 1;
    }
    
    std::cout << "Output saved to " << outputFile << "\n";
    return 0;
}
