#include "header.h"
#include <iostream>
#include <fstream>
#include <limits>

#define ARRAY_SIZE 105 // Defining the size of the array as 200

using namespace std;

// Function to find an element in the array by value and return its index
void findElement(int array[], int size)
{
	int target;
	string input;

	try
	{
		cout << "Target Value: "; // Asking user for the value to search
		cin >> input;

		size_t pos;
		target = stoi(input, &pos);

		if (pos < input.length()) {
			throw invalid_argument("Input must be an integer.");
		}

		// Loop through the array to find the target value
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			if (array[i] == target)
			{
				cout << target << " found at index " << i << endl; // Print the index where the target is found
				cout << endl;
				return;
			}
		}
		cout << target << " not found\n"
			 << endl; // If the value is not found, inform the user
	}
	catch (const invalid_argument &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl; // Handle invalid argument exceptions
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl; // Catch any other exceptions
	}
	catch (...)
	{
		cerr << "Undefined exception occurred\n"
			 << endl;
	}
}

// Function to modify an element in the array by index, showing the old and new values
void modifyElement(int array[], int size)
{
	int index;
	int newValue;
	string input;
	string input2;

	try
	{
		cout << "Index: "; // Ask user for the index to modify
		cin >> input;

		// Handling input errors
		size_t pos;
		index = stoi(input, &pos);

		if (pos < input.length()) {
			throw invalid_argument("Input must be an integer.");
		}

		// Check if the index is within valid range
		if (index < 0 || index >= size)
		{
			throw out_of_range("Index is out of valid range."); // Throw exception if index is out of bounds
		}

		cout << "New Value: "; // Ask for the new value to be inserted at the specified index
		cin >> input2;

		// Handling input errors
		size_t pos2;
		newValue = stoi(input2, &pos2);

		if (pos < input.length()) {
			throw invalid_argument("Input must be an integer.");
		}

		cout << "Old value: " << array[index] << endl; // Display the old value at the index
		array[index] = newValue;					   // Assign new value to the array at the specified index
		cout << "New value: " << array[index] << endl; // Display the new value

		// Print the entire array after modification
		cout << "Array contents: " << endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			cout << array[i] << " ";
		}
		cout << "\n"
			 << endl;
	}
	catch (const out_of_range &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl;
	}
	catch (const invalid_argument &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl;
	}
	catch (const exception &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl;
	}
	catch (...)
	{
		cerr << "Undefined exception occurred\n"
			 << endl;
	}
}

// Function to add a new element to the array if there is available space
void addElement(int array[], int capacity, int &size)
{
	int newValue;
	string input;

	try
	{
		cout << "New Value: "; // Ask for the new value to add to the array
		cin >> input;

		// Handling input errors
		size_t pos;
		newValue = stoi(input, &pos);

		if (pos < input.length()) {
			throw invalid_argument("Input must be an integer.");
		}

		// Check if there's space left in the array
		if (size < capacity)
		{
			array[size] = newValue; // Add the new value to the end of the array
			size++;					// Increment the size of the array
		}
		else
		{
			cout << "Array is full" << endl; // Inform the user if the array is full
		}

		// Print the updated array
		cout << "Array contents: " << endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			cout << array[i] << " ";
		}
		cout << "\n"
			 << endl;
	}
	catch (const invalid_argument &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl;
	}
	catch (const exception &e)
	{
		cerr << "Error: Invalid Input\n"
			 << endl;
	}
	catch (...)
	{
		cerr << "Undefined exception occurred\n"
			 << endl;
	}
}
// Function to delete an element from the array by shifting elements left
void deleteElement(int array[], int &size)
{
	int index;
	string input;

	try
	{
		cout << "Index: "; // Ask for the index to delete
		cin >> input;

		// Handling input errors
		size_t pos;
		index = stoi(input, &pos);

		if (pos < input.length()) {
			throw invalid_argument("Input must be an integer.");
		}

		// Check if index is within range
		if (index >= 0 && index < size)
		{
			// Shift elements to the left to "delete" the element at the specified index
			for (int i = index; i < size - 1; i++)
			{
				array[i] = array[i + 1];
			}
			size--;			 // Reduce the size of the array
			array[size] = 0; // Set the last element to 0
		}
		else
		{
			cout << "Invalid Index" << endl; // Inform if index is out of bounds
		}

		// Print the updated array
		cout << "Array contents: " << endl;
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			cout << array[i] << " ";
		}
		cout << "\n"
			 << endl;
	}
	catch (const invalid_argument &e)
	{
		cerr << "Error: " << e.what() << "\n"
			 << endl;
	}
	catch (const exception &e)
	{
		cerr << "Error: Invalid Input" << "\n"
			 << endl;
	}
	catch (...)
	{
		cerr << "Undefined exception occurred\n"
			 << endl;
	}
}

int main()
{
	const int capacity = ARRAY_SIZE; // Define the maximum capacity of the array
	int array[capacity] = {0};		 // Initialize an array of size 'capacity' filled with zeros
	int size = 0;					 // current array size

	// Open the input file to read the array elements
	ifstream inputFile("A1input.txt");

	// Check if the file is successfully opened
	if (!inputFile.is_open())
	{
		cout << "Can't open the file" << endl;
		return -1;
	}

	// Read integers from the input file into the array
	while (inputFile >> array[size] && size < capacity)
	{
		size++;
	}
	inputFile.close(); // Close the file

	// Print the contents of the array after reading from the file
	cout << "Array contents: " << endl;
	for (int i = 0; i < capacity; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n"
		 << endl;

	int num = 0;
	string input;

	// Menu to allow the user to choose different operations
	while (num != 5)
	{
		// Prompt the user to enter a menu option
		cout << "1. Find an element by value." << endl;
		cout << "2. Change an element with an index." << endl;
		cout << "3. Add an array at the end of the array." << endl;
		cout << "4. Delete an element with an index." << endl;
		cout << "5. Exit the program" << endl;
		cout << "Enter a number (1-5): ";
		try
		{
			// Read the user input
			cin >> input;

			// Handling input errors
			size_t pos;
			num = stoi(input, &pos);

			if (pos < input.length()) {
				throw invalid_argument("Input must be an integer.");
			}

			// Switch case to handle menu options
			switch (num)
			{
			case 1: // Option to find an element by value
				cout << endl;
				findElement(array, size);
				break;
			case 2: // Option to modify an element by index
				cout << endl;
				modifyElement(array, size);
				break;
			case 3: // Option to add a new element to the array
				cout << endl;
				addElement(array, capacity, size);
				break;
			case 4: // Option to delete an element by index
				cout << endl;
				deleteElement(array, size);
				break;
			case 5: // Option to exit the program
				cout << endl;
				cout << "Finish the program\n"
					 << endl;
				break;
			default: // Handle invalid menu options
				cout << "Invalid number\n"
					 << endl;
				break;
			}
		}
		catch (const invalid_argument &e)
		{
			// Handle input errors
			cerr << "Error: " << e.what() << "\n"
				 << endl;
		}
		catch (const exception &e)
		{
			cerr << "Error: Invalid Input" << "\n"
				 << endl;
		}
		catch (...)
		{
			cerr << "Undefined exception occurred\n"
				 << endl;
		}
	}

	return 0;
}