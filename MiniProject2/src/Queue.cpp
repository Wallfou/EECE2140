#include "../include/Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    frontOfQueue = 0;
    backOfQueue = -1;
    count = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        throw overflow_error("queue full");
    }
    backOfQueue = (backOfQueue + 1) % capacity;
    arr[backOfQueue] = item;
    count++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw underflow_error("queue empty");
    }
    int item = arr[frontOfQueue];
    frontOfQueue = (frontOfQueue + 1) % capacity;
    count--;
    return item;
}

int Queue::peek() const {
    if (isEmpty()) {
        throw underflow_error("queue empty");
    }
    return arr[frontOfQueue];
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::isFull() const {
    return count == capacity;
}

int Queue::size() const {
    return count;
}

void Queue::clear() {
    frontOfQueue = 0;
    backOfQueue = -1;
    count = 0;
}

void Queue::printQueue() const {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = 0; i < count; i++) {
        int index = (frontOfQueue + i) % capacity;
        cout << arr[index] << " ";
    }
    cout << endl;
}
