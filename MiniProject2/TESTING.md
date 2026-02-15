## Testing

# Enqueue until full  
kennethfan@Mac MiniProject2 % ./main

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 4
Error: queue full

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 4
Size of queue: 5

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 7

# Dequeue until empty  
kennethfan@Mac MiniProject2 % ./main

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 1

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
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 5

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 6
Error: queue full

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue: 1 2 3 4 5 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: 1

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
Input: 2
Removed value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: 5

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: Error: queue empty

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue is empty

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 7

# Wrap-around test  
kennethfan@Mac MiniProject2 % ./main

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 1

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
Enter value: 4

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 5

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue: 1 2 3 4 5 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: 1

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
Queue: 3 4 5 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 6

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 7

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 5
Queue: 3 4 5 6 7 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 7

# Mixed operations  
kennethfan@Mac MiniProject2 % ./main

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 1
Enter value: 1

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
Input: 5
Queue: 1 2 

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 3
Peek: 1

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 2
Removed value: 1

menu
1: enqueue
2: dequeue
3: peek
4: size
5: print
6: clear
7: exit
Input: 3
Peek: 2

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
Input: 5
Queue: 2 

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