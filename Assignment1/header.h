#pragma once

void findElement(int array[], int size);	// check a certain integer and return the index
void modifyElement(int array[], int size);	// modify the value and return old value and new value
void addElement(int array[], int capacity, int& size);	// add a new integer to the end of the array
void deleteElement(int array[], int index, int& size);	// replace the value with either 0 or remove the integer altogether