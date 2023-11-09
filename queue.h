#ifndef CUSTOMQUEUE_H
#define CUSTOMQUEUE_H

#include <iostream>
#include <queue>

// Class definition for CustomQueue
class CustomQueue {
public:
    // Inserts a new element at the rear of the queue.
    void enqueue(int value);

    // Removes the front element of the queue and returns it.
    // If the queue is empty, returns -1 to indicate an empty queue.
    int dequeue();

    // Returns the front element present in the queue without removing it.
    // If the queue is empty, returns -1 to indicate an empty queue.
    int front();

    // Checks if the queue is empty.
    bool isEmpty();

    // Returns the total number of elements present in the queue.
    int size();

    // Prints all elements in the queue.
    void printQueue();

private:
    std::queue<int> myQueue; // Internal representation of the queue.
};

#endif // CUSTOMQUEUE_H