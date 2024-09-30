# Datst Structre
## Assignment 2 Report

### Overview
This project consists of two separate implementations in C++:
1. **Single Linked List:** A custom implementation of a singly linked list supporting basic list operations such as insertion, deletion, and element lookup.
2. **Vector-based Stack:** A stack of integers implemented using std::vector, supporting common stack operations like push, pop, and top, along with an additional feature to calculate the average of the stack elements.

### Features
1. **Single Linked List** 
- **push_front:** Insert an element at the front of the list.
- **push_back:** Insert an element at the back of the list.
- **pop_front:** Remove the element from the front of the list.
- **pop_back:** Remove the element from the back of the list.
- **front:** Access the element at the front of the list.
- **back:** Access the element at the back of the list.
- **empty:** Check if the list is empty.
- **insert(index, item):** Insert an element at a specific index.
- **remove(index):** Remove an element from a specific index.
- **find(item):** Find the first occurrence of an item in the list.
- **size:** Get the number of elements in the list.

2. **Vector-based Stack**
- **push:** Add an element to the top of the stack.
- **pop:** Remove the element from the top of the stack.
- **top:** Access the element at the top of the stack.
- **is_empty:** Check if the stack is empty.
- **average:** Calculate the average value of all elements in the stack.
- **size** Get the number of elements in the stack.


### Files
- `main.cpp`: 
  - Contains the implementation of the Single Linked List methods.
  - Contains the implementation of the Vector-based Stack methods.
  - Contains the test code to demonstrate the functionality of both the Single Linked List and the Stack.
- `header.h`:
  - Contains the class declaration and function prototypes for the Single Linked List.
  - Contains the class declaration and function prototypes for the Vector-based Stack.

## How to Run
1. Compile the program using a C++ compiler, for example:
   ```css
   g++ -o assignment2 main.cpp
   ```
3. Run the program:
   ```bash
   ./assignment2
   ```
