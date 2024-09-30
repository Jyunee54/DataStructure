# Datst Structre
## Assignment 1 Report

**Description**
This program demonstrates basic array manipulation operations such as finding an element by value, modifying an element by index, adding a new element, and deleting an element by index. The program reads an array of integers from an input file and provides a menu-driven interface to perform these operations interactively.

**Input**
- The program reads an array of integers from the file A1input.txt, which contains a list of integers in a matrix format.
- The array has a maximum capacity of 200 elements, but the actual size depends on the number of integers read from the input file.

**Features**
1. **Find an Element:** Allows the user to search for an element in the array by providing a value. If the value exists in the array, the program returns the index.
2. **Modify an Element:** Allows the user to modify the value at a specified index, showing both the old and new values.
3. **Add an Element:** Allows the user to append a new element to the array if there is space.
4. **Delete an Element:** Allows the user to delete an element at a specified index by shifting subsequent elements to the left.

**Files**
- `main.cpp`: The main program containing the logic for array manipulation.
- `header.h`: Header file declaring the functions used in the program【6†source】.
- `A1input.txt`: Input file containing an array of integers【7†source】.
 
**How to Run**
1. Ensure that `A1input.txt` is in the same directory as the program.
2. Compile the program using a C++ compiler, for example:
   ```css
   g++ -o assignment1 main.cpp
   ```
3. Run the program:
   ```bash
   ./assignment1
   ```
4. Follow the on-screen instructions to interact with the array.

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
