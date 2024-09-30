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


**Files**
- `main.cpp`: 
  - Contains the implementation of the Single Linked List methods.
  - Contains the implementation of the Vector-based Stack methods.
  - Contains the test code to demonstrate the functionality of both the Single Linked List and the Stack.
- `header.h`:
  - Contains the class declaration and function prototypes for the Single Linked List.
  - Contains the class declaration and function prototypes for the Vector-based Stack.

**How to Run**
1. Compile the program using a C++ compiler, for example:
   ```css
   g++ -o assignment2 main.cpp
   ```
3. Run the program:
   ```bash
   ./assignment2
   ```

**User Instructions**
- Choose from the menu options to perform operations on the array:
  1. Find an element by value
  2. Modify an element by index
  3. Add a new element
  4. Delete an element by index
  5. Exit the program

![image](https://github.com/user-attachments/assets/e7eb8c14-e1da-4785-b57d-3c1cd7d7f524)
1. Find an element by value
   - If a value is found
     
     ![image](https://github.com/user-attachments/assets/422f4aec-c7d7-40f8-8e15-d4d44caa6ff7)
     
   - If the value is not found
     
     ![image](https://github.com/user-attachments/assets/05b5943e-535b-49de-b448-6fbe023092e7)
     
2. Modify an element by index
   - If the value has changed successfully
     
     ![image](https://github.com/user-attachments/assets/36a59ca9-1773-4c35-9227-d1fb7d97f3ab)
     
   - Out of index range
     
     ![image](https://github.com/user-attachments/assets/7427acaf-4ea5-4c28-b566-cda81620bf61)
     
3. Add a new element
   - If the value is added successfully
     
     ![image](https://github.com/user-attachments/assets/e5efef6d-6f12-4b6a-990b-771131a42f57)
     
   - If the array is full
     
     ![image](https://github.com/user-attachments/assets/ae3d17e7-ddac-4c93-8fa9-810723865836)
    
4. Delete an element by index
   - If the value is deleted successfully
     
     ![image](https://github.com/user-attachments/assets/4c025d22-f547-4b44-8353-1a315a9ea5f8)
     
   - Out of index range
     
     ![image](https://github.com/user-attachments/assets/aee805cb-8d3b-44d2-8cf3-ca5144166a63)
     
5. Exit the program
   
   ![image](https://github.com/user-attachments/assets/0fb8f407-4caf-4a97-9747-f73e731cf9a5)

**Error Handling**
- The program handles invalid input, including non-integer values and out-of-rangeindices, with error messages.
  - In this program, the input always allows only integers, so if you enter another type, you will output an error message.
    
    ![image](https://github.com/user-attachments/assets/d7359e1c-a9f1-497a-b38c-b13870defeb9)
    
  - If an invalid number is entered in the main menu, an error message is output.
    
    ![image](https://github.com/user-attachments/assets/065292fe-abfa-4f32-a960-a258f755f8f0)
    
- When modifying or deleting elements, the program checks whether the provided index is valid before proceeding.

**Dependecies**
- C++ Standard Library (iostream, fstream)
