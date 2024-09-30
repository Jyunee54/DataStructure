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

### 3. Key Components

#### 3.1 Single Linked List Implementation

This implementation uses a custom `Node` structure to represent the linked list. The list supports both front and back insertions as well as deletions. It also provides functionality to find specific elements and check if the list is empty.

Example method:
```c
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type &item)
{
    Node *new_node = new Node(item, head);
    head = new_node;
    if (!tail)
    {
        tail = head;
    }
    num_items++;
}
```
This method inserts a new node at the front of the linked list.

#### 3.2 Vector-based Stack Implementation

The stack is implemented using the `vector<int>` container, leveraging its dynamic array capabilities. The stack provides essential operations like push, pop, and top retrieval, as well as a method to calculate the average of the stack elements.

Example method:
```c
double Stack::average() const
{
    if (is_empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    double sum = std::accumulate(stack.begin(), stack.end(), 0);
    return sum / static_cast<double>(stack.size());
}
```
This method calculates the average value of the elements in the stack. If the stack is empty, it throws an exception.

### 4. Error Handling
The program includes robust error handling to manage situations where the stack is empty or where user input is invalid.

1. **Empty Stack Exception:** When trying to perform operations like `pop()` or `top(`) on an empty stack, the program throws an `out_of_range` exception, ensuring the user is informed of invalid actions.
2. **Input Validation:** The `get_valid_input()` function ensures that only integers are accepted as input. If a non-integer value is entered, the program clears the error flags on the input stream, discards invalid input, and prompts the user for a valid integer.

Example of input validation:
```c
int get_valid_input()
{
    int value;
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter an integer: ";
        }
        else
        {
            return value;
        }
    }
}
```

### 5. How to Run
1. Compile the program using a C++ compiler, for example:
   ```css
   g++ -o assignment2 main.cpp
   ```
3. Run the program:
   ```bash
   ./assignment2
   ```

### 6. Execution Flow
When the program is run, the user is presented with the following menu:
```
--- Stack Operations ---
1. Push a value onto the stack
2. Pop a value from the stack
3. Check the top of the stack
4. Check if stack is empty
5. Get the average of stack elements
6. Exit
```

- The user selects an operation by entering the corresponding number.
- The program executes the selected operation and displays the result.
- If the user enters an invalid choice, the program prompts them to try again.
- This process continues until the user selects option 6, which exits the program.

### 7. Conclusion
This project demonstrates how to implement and manage custom data structures using C++. The **Single Linked List** and **Vector-based Stack** are both fundamental components of computer science, providing insight into dynamic memory management, container classes, and exception handling in C++. The project showcases the utility of `vector` in building a stack and highlights robust input validation and error handling techniques to ensure a smooth user experience.