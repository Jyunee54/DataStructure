#include "header.h"
#include <iostream>
#include <fstream>

#define ARRAY_SIZE 200

using namespace std;

// check a certain integer and return the index
void findElement(int array[], int size) {
	int target;
	try {
		cout << "Target Value: ";
		cin >> target;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Index must be an integer");
		}

		for (int i = 0; i < ARRAY_SIZE; i++) {
			if (array[i] == target) {
				cout << target << " found at index " << i << endl;
				return;
			}
		}
		cout << target << " not found" << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}
// modify the value and return old value and new value
void modifyElement(int array[], int size) {
	int index;
	int newValue;

	try {
		cout << "Index: ";
		cin >> index;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Index must be an integer");
		}

		if (index < 0 || index >= size) {
			throw out_of_range("Index is out of valid range");
		}

		cout << "New Value: ";
		cin >> newValue;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Index must be an integer");
		}

		cout << "Old value: " << array[index] << endl;
		array[index] = newValue;
		cout << "New value: " << array[index] << endl;

		// print the array
		cout << "Array contents: " << endl;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			cout << array[i] << " ";
		}
		cout << "\n" << endl;
	}
	catch (const out_of_range& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
}

// add a new integer to the end of the array
void addElement(int array[], int capacity, int& size) {
	int newValue;

	try {
		cout << "New Value: ";
		cin >> newValue;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Index must be an integer");
		}
		
		if (size < capacity) {
			array[size] = newValue;
			size++;
		}
		else {
			cout << "Array is full" << endl;
		}

		// print the array
		cout << "Array contents: " << endl;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			cout << array[i] << " ";
		}
		cout << "\n" << endl;

	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << "Error: Invalid Input" << endl;
	}
}
// replace the value with either 0 or remove the integer altogether
void deleteElement(int array[], int& size) {
	int index;

	try {
		cout << "Index: ";
		cin >> index;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			throw invalid_argument("Index must be an integer");
		}

		if (index >= 0 && index < size) {
			for (int i = index; i < size - 1; i++) {
				array[i] = array[i + 1];
			}
			size--;
			array[size] = 0;
		}
		else {
			cout << "Invalid Index" << endl;
		}

		// print the array
		cout << "Array contents: " << endl;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			cout << array[i] << " ";
		}
		cout << "\n" << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
	catch (const exception& e) {
		cerr << "Error: Invalid Input" << endl;
	}
}

int main() {
	const int capacity = ARRAY_SIZE;
	int array[capacity] = { 0 };
	int size = 0;				// current array size

	ifstream inputFile("A1input.txt");

	if (!inputFile.is_open()) {
		cout << "Can't open the file" << endl;
		return -1;
	}
	
	while (inputFile >> array[size] && size < capacity) {
		size++;
	}
	inputFile.close();

	// print the array
	cout << "Array contents: " << endl;
	for (int i = 0; i < capacity; i++) {
		cout << array[i] << " ";
	}
	cout << "\n" << endl;

	int num = 0;

	while (num != 5) {
		cout << "Enter a number (1-5): ";
		try {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("Index must be an integer");
			}
			switch (num) {
			case 1:
				findElement(array, size);
				break;
			case 2:
				modifyElement(array, size);
				break;
			case 3:
				addElement(array, capacity, size);
				break;
			case 4:
				deleteElement(array, size);
				break;
			case 5:
				cout << "Finish the program" << endl;
				break;
			default:
				cout << "Invalid number" << endl;
				break;
			}
		}
		catch (const invalid_argument& e) {
			cerr << "Error: " << e.what() << endl;
		}
		catch (const exception& e) {
			cerr << "Error: Invalid Input" << endl;
		}
	}

	return 0;
}