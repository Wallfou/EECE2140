# MiniProject4 - Circular Queue Implementation

## Build
g++ src/Queue.cpp src/main.cpp -o main

## Run
./main

## Structure
- include/Queue.h
- src/Queue.cpp
- src/main.cpp
- README.md
- TESTING.md

## Example Usage

```
menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 2

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 3

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 15

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue: 2 3 15 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: 2

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue: 3 15 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 4
Size of queue: 2

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 3
Peek: 3

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: 3

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue: 15 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 4
Size of queue: 1

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 6
cleraed

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 4
Size of queue: 0

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 7
```