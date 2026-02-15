#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

class Queue {
private:
    int* arr;
    int capacity;
    int frontOfQueue;
    int backOfQueue;
    int count;

public:
    Queue(int size = 10);
    ~Queue();

    void enqueue(int item);
    int dequeue();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void clear();
    void printQueue() const;
};

#endif
