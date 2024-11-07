#ifndef INSERTION_SORT_LIST_HPP
#define INSERTION_SORT_LIST_HPP

#include <iostream>

// Node structure for linked list
struct ListNode
{
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Linked list class that supports insertion and insertion sort
class InsertionSortList
{
public:
    InsertionSortList();  // Constructor
    ~InsertionSortList(); // Destructor to release memory

    void insert(int value); // Function to insert a new node
    void sort();            // Function to sort the linked list
    void printList() const; // Function to print the list elements

private:
    ListNode *head; // Head pointer for the linked list
};

#endif // INSERTION_SORT_LIST_HPP