#include "Queue.hpp"
#include <iostream>

// Constructor: initializes an empty queue
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

// Destructor: clears all nodes in the queue
template <typename T>
Queue<T>::~Queue()
{
    while (!empty())
    {
        pop();
    }
}

// Adds a new element to the rear of the queue
template <typename T>
void Queue<T>::push(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (empty())
    {
        frontNode = rearNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    queueSize++;
}

// Removes the front element from the queue
template <typename T>
void Queue<T>::pop()
{
    if (empty())
    {
        std::cerr << "Queue is empty. Cannot pop." << std::endl;
        return;
    }
    Node<T> *temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    queueSize--;
    if (empty())
    {
        rearNode = nullptr;
    }
}

// Returns the front element without removing it
template <typename T>
T Queue<T>::front()
{
    if (empty())
    {
        throw std::runtime_error("Queue is empty.");
    }
    return frontNode->data;
}

// Returns the current size of the queue
template <typename T>
int Queue<T>::size()
{
    return queueSize;
}

// Checks if the queue is empty
template <typename T>
bool Queue<T>::empty()
{
    return queueSize == 0;
}

// Moves the front element to the rear of the queue
template <typename T>
void Queue<T>::move_to_rear()
{
    if (empty() || queueSize == 1)
    {
        return;
    }
    T frontValue = front();
    pop();
    push(frontValue);
}

// Displays all elements in the queue (for debugging)
template <typename T>
void Queue<T>::display()
{
    Node<T> *current = frontNode;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function to test the Queue implementation
int main()
{
    //----------- Q1 -----------//
    // Instantiate the queue with integers
    Queue<int> q;

    // Push 10 integer values into the queue
    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }

    // Display all elements in the queue
    std::cout << "Queue elements: ";
    q.display();

    // Move the front element to the rear
    q.move_to_rear();

    // Display elements after moving front to rear
    std::cout << "After moving front to rear: ";
    q.display();

    return 0;
}