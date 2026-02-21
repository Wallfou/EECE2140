# Image Denoising

C++ program that denoises grayscale images using neighborhood filters.

## Build

```bash
make
```

or manually:
```bash
g++ -std=c++11 -Iinclude src/main.cpp src/Image.cpp src/Filter.cpp -o denoise
```

## Usage

```bash
./denoise <input> <output> <filter> [iterations] [border]
```

Examples:
```bash
./denoise tests/test1_small.txt output.txt mean
./denoise tests/test2_impulse_noise.txt output.txt median 2
./denoise tests/test3_edges.txt output.txt mean 1 zero
```

Input file format:
```
rows cols
val11 val12 ...
val21 val22 ...
```

Run tests:
```bash
make test
```

## Implementation

Image class - loads/saves matrices, stores as vector<vector<int>>
Filter class - mean and median filters with 3x3 neighborhoods
Border handling - clamp, zero padding, or ignore

Mean filter: averages 3x3 neighborhood
Median filter: takes median of 3x3 neighborhood (better for salt and pepper noise)

Border policies:
- clamp: replicate edge pixels
- zero: use 0 for out of bounds
- ignore: only filter interior pixels

## Copilot Usage

Copilot helped with:
- Initial boilerplate for Image and Filter classes
- Argument parsing structure
- Makefile template

I wrote/verified:
- Border handling logic
- Statistics calculations
- Test cases
- Iterative filtering

Bug found:
Copilot suggested using int** but I changed it to vector<vector<int>> to avoid memory leaks.

## Output

```
Before denoising:
Image Statistics:
  Dimensions: 5x5
  Mean: 124.8
  Std Dev: 56.8239

After denoising:
Image Statistics:
  Dimensions: 5x5
  Mean: 124.48
  Std Dev: 18.0424

Noise reduction: 68.2485%
Output saved to output/test.txt
```