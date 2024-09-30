# Datst Structre
## Assignment 2 Report

### 1. Overview
This project consists of two separate implementations in C++:
1. **Single Linked List:** A linked list that allows insertion and deletion from both the front and back.
2. **Vector-based Stack:** A stack implementation using `vector` with basic stack operations such as `push`, `pop`, `top`, and `average`.

The program includes functionalities to:
- Push and pop elements to/from the stack.
- Check if the stack is empty.
- View the top element in the stack.
- Calculate the average of the stack elements.
- Validate user inputs and handle exceptions for invalid input types.

### 2. Structure
#### 2.1 Header Files (`header.h`)
This file defines two classes: `Single_Linked_List` and `Stack`.

**Single_Linked_List Class:**
- Node structure: Stores data and a pointer to the next node.
- Core Methods:
  - `push_front()`: Inserts an element at the front of the list.
  - `push_back()`: Inserts an element at the back of the list.
  - `pop_front()`: Removes an element from the front.
  - `pop_back()`: Removes an element from the back.
  - `insert()`: Inserts an element at a specific index.
  - `remove()`: Removes an element at a specific index.
  - `find()`: Finds the index of a specific element.
  - `empty()`: Checks if the list is empty.
  - `size()`: Returns the size of the list.


**Stack Class:**
- Member Variables:
  - `vector<int> stack`: Stores the stack elements.
- Core Methods:
  - `push()`: Pushes an integer value onto the stack.
  - `pop()`: Removes the top element from the stack.
  - `top()`: Returns the top element of the stack.
  - `average()`: Computes the average of the stack elements.
  - `is_empty()`: Checks if the stack is empty.
  - `size()`: Returns the current size of the stack.


#### 2.2 Main File (`main.cpp`)
This fle contains the implementation of the Single Linked List methods and Vector-based Stack methods.

And, it also contains the main function and user interaction code for the stack operations. It presents a menu-driven system for users to perform the following tasks:

- Push values onto the stack.
- Pop values from the stack.
- View the top element.
- Check if the stack is empty.
- Calculate and display the average value of the elements in the stack.

It also includes a function get_valid_input() to ensure that the user inputs a valid integer and handles non-integer inputs by prompting the user again.


### How to Run
1. Compile the program using a C++ compiler, for example:
   ```css
   g++ -o assignment2 main.cpp
   ```
3. Run the program:
   ```bash
   ./assignment2
   ```
