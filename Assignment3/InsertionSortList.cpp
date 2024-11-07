#include "InsertionSortList.hpp"

// Constructor: Initializes the head pointer to null
InsertionSortList::InsertionSortList() : head(nullptr) {}

// Destructor: Releases memory allocated for each node
InsertionSortList::~InsertionSortList()
{
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// Inserts a new node with a given value at the beginning of the list
void InsertionSortList::insert(int value)
{
    ListNode *newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

// Sorts the linked list using insertion sort algorithm
void InsertionSortList::sort()
{
    if (!head || !head->next) // If the list is empty or has only one element, no need to sort
        return;

    ListNode *sorted = nullptr; // Temporary sorted list

    while (head)
    {
        ListNode *current = head;
        head = head->next; // Detach the node from the head of the unsorted list

        // Insert current node into the sorted list
        if (!sorted || sorted->value >= current->value)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            ListNode *temp = sorted;
            while (temp->next && temp->next->value < current->value)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sorted; // Update head to point to the sorted list
}

// Prints all elements in the list
void InsertionSortList::printList() const
{
    ListNode *temp = head;
    while (temp)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    InsertionSortList list;
    list.insert(65);
    list.insert(20);
    list.insert(30);
    list.insert(10);
    list.insert(5);
    list.insert(35);

    std::cout << "Before sorting: ";
    list.printList();

    list.sort();

    std::cout << "After sorting: ";
    list.printList();

    return 0;
}