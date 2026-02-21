# Testing Documentation

How to Run Tests

Run all tests:
```bash
make test
```

Run individual tests:
```bash
make
./denoise tests/test1_small.txt output/test1.txt mean
./denoise tests/test2_impulse_noise.txt output/test2.txt median 2
./denoise tests/test3_edges.txt output/test3.txt mean 1 clamp
```

## Test Cases

Test 1: Small Matrix:

Input:
```
5 5
100 100 100 100 100
100 100 255 100 100
100 255 100 255 100
100 100 255 100 100
100 100 100 100 100
```

Command: `./denoise tests/test1_small.txt output/test1.txt mean`

Results:

before: Mean=124.8, StdDev=56.82
after: Mean=124.48, StdDev=18.04
Noise reduction: 68.25%


Test 2: Impulse Noise

Input:
```
8 8
50 50 255 50 50 0 50 50
50 50 50 50 255 50 50 0
0 50 50 50 50 50 255 50
50 255 50 50 50 0 50 50
50 50 50 255 50 50 50 50
255 50 0 50 50 50 255 50
50 50 50 50 0 50 50 50
50 0 50 255 50 50 50 255
```

Command: `./denoise tests/test2_impulse_noise.txt output/test2.txt median 2`

Results:

before: Mean=73.36, StdDev=75.08
after: Mean=50, StdDev=0
noise reduction: 100%

Test 3: Edge Behavior

Input:
```
6 6
255 0 0 0 0 255
0 100 100 100 100 0
0 100 100 100 100 0
0 100 100 100 100 0
0 100 100 100 100 0
255 0 0 0 0 255
```

Commands:
```bash
./denoise tests/test3_edges.txt output/test3_clamp.txt mean 1 clamp
./denoise tests/test3_edges.txt output/test3_zero.txt mean 1 zero
./denoise tests/test3_edges.txt output/test3_ignore.txt mean 1 ignore
```

Results (clamp):

before: mean=72.78, stddev=79.83
after: mean=72.22, stddev=27.23
noise reduction: 65.89%


Test 4: Gradient

Input:
```
5 10
0 25 50 75 100 125 150 175 200 225
0 25 50 75 100 125 150 175 200 225
0 25 50 75 100 125 150 175 200 225
0 25 50 75 100 125 150 175 200 225
0 25 50 75 100 125 150 175 200 225
```

Command: `./denoise tests/test4_gradient.txt output/test4.txt mean`

Results:
before: mean=112.5, stddev=71.81
after: mean=112.4, stddev=69.20
noise reduction: 3.63%
