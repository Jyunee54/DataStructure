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
**Error Handling**
- The program handles invalid input, including non-integer values and out-of-rangeindices, with error messages.
- When modifying or deleting elements, the program checks whether the provided index is valid before proceeding.
**Dependecies**
- C++ Standard Library (iostream, fstream)
