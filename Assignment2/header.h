#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>

template <typename Item_Type>
class Single_Linked_List
{
private:
	struct Node
	{
		Item_Type data;
		Node *next;
		Node(const Item_Type &data, Node *next = nullptr) : data(data), next(next) {}
	};

	Node *head;
	Node *tail;
	size_t num_items;

public:
	Single_Linked_List();
	~Single_Linked_List();

	void push_front(const Item_Type &item);
	void push_back(const Item_Type &item);
	void pop_front();
	void pop_back();
	const Item_Type &front() const;
	const Item_Type &back() const;
	bool empty() const;
	void insert(size_t index, const Item_Type &item);
	bool remove(size_t index);
	size_t find(const Item_Type &item) const;
	size_t size() const;
};

class Stack
{
private:
	std::vector<int> stack;

public:
	bool is_empty() const;
	void push(int value);
	void pop();
	int top() const;
	double average() const;
	size_t size() const;
	void print_stack() const; // New function to print the stack
};