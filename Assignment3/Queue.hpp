#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

// Node structure for each element in the Queue
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T value) : data(value), next(nullptr) {}
};

// Queue class definition
template <typename T>
class Queue
{
private:
    Node<T> *frontNode; // Pointer to the front node
    Node<T> *rearNode;  // Pointer to the rear node
    int queueSize;      // Tracks the size of the queue

public:
    Queue();  // Constructor
    ~Queue(); // Destructor

    void push(T value);  // Adds an element to the queue
    void pop();          // Removes the front element from the queue
    T front();           // Returns the front element without removing it
    int size();          // Returns the current size of the queue
    bool empty();        // Checks if the queue is empty
    void move_to_rear(); // Moves the front element to the rear of the queue

    void display(); // Display function for debugging
};

#endif // QUEUE_HPP