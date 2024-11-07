#ifndef LINEAR_SEARCH_LAST_HPP
#define LINEAR_SEARCH_LAST_HPP

#include <vector>

// Function declaration for finding the last occurrence of a target in a vector using recursion
template <typename Item_Type>
int linear_search_last(const std::vector<Item_Type> &items, const Item_Type &target, std::size_t pos_first = 0);

// Declaration of the function to print elements of a vector
template <typename Item_Type>
void printVector(const std::vector<Item_Type> &items);

#endif // LINEAR_SEARCH_LAST_HPP