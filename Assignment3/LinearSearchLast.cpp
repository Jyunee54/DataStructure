#include "LinearSearchLast.hpp"
#include <iostream>
#include <iomanip>

// Function to find the last occurrence of the target in a vector recursively
template <typename Item_Type>
int linear_search_last(const std::vector<Item_Type> &items, const Item_Type &target, std::size_t pos_first)
{
    if (pos_first == items.size())
    {
        // Base case: reached the end of the vector, return -1 if target not found
        return -1;
    }

    // Recursively search the next position
    int result = linear_search_last(items, target, pos_first + 1);

    if (result != -1)
    {
        // If the target is found in the subsequent position, return that position
        return result;
    }

    // If the target is found at the current position, return this position
    if (items[pos_first] == target)
    {
        return pos_first;
    }

    // If target is not found, return -1
    return -1;
}

// Detailed function to print the elements of a vector
template <typename Item_Type>
void printVector(const std::vector<Item_Type> &items)
{
    std::cout << "Vector elements: [ ";
    for (const auto &item : items)
    {
        std::cout << item << " ";
    }
    std::cout << "]" << std::endl;

    // Displaying index positions for clarity
    std::cout << "Index positions: ";
    for (size_t i = 0; i < items.size(); ++i)
    {
        std::cout << std::setw(2) << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Declare a vector of integers and add some numbers
    std::vector<int> items = {1, 2, 3, 4, 2, 5, 2};

    // Define the target value to search
    int target = 2;

    // Print the vector elements before searching
    printVector(items);

    // Call the linear_search_last function to find the last occurrence of the target
    int last_position = linear_search_last(items, target);

    if (last_position != -1)
    {
        std::cout << "The last occurrence of " << target << " is at index: " << last_position << std::endl;
    }
    else
    {
        std::cout << target << " was not found in the vector." << std::endl;
    }

    return 0;
}