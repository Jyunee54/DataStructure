#include "header.h"
#include <limits>

using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List()
{
    while (!empty())
    {
        pop_front();
    }
}

// Insert front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type &item)
{
    Node *new_node = new Node(item, head);
    head = new_node;
    if (!tail)
    {
        tail = head;
    }
    num_items++;
}

// Insert back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type &item)
{
    Node *new_node = new Node(item);
    if (tail)
    {
        tail->next = new_node;
    }
    else
    {
        head = new_node;
    }
    tail = new_node;
    num_items++;
}

// Remove front of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front()
{
    if (!empty())
    {
        Node *old_head = head;
        head = head->next;
        delete old_head;
        num_items--;
        if (!head)
        {
            tail = nullptr;
        }
    }
}

// Remove back of the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back()
{
    if (!empty())
    {
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        num_items--;
    }
}

// Return item front of the list
template <typename Item_Type>
const Item_Type &Single_Linked_List<Item_Type>::front() const
{
    if (empty())
    {
        throw out_of_range("List is empty");
    }
    return head->data;
}

// Return item back of the list
template <typename Item_Type>
const Item_Type &Single_Linked_List<Item_Type>::back() const
{
    if (empty())
    {
        throw out_of_range("List is empty");
    }
    return tail->data;
}

// Check the list is empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const
{
    return num_items == 0;
}

// Insert item at the specific index
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type &item)
{
    if (index > num_items)
    {
        push_back(item);
        return;
    }
    if (index == 0)
    {
        push_front(item);
        return;
    }

    Node *current = head;
    for (size_t i = 1; i < index; ++i)
    {
        current = current->next;
    }
    Node *new_node = new Node(item, current->next);
    current->next = new_node;
    num_items++;
}

// Remove item at the specific index
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index)
{
    if (index >= num_items)
    {
        return false;
    }
    if (index == 0)
    {
        pop_front();
        return true;
    }

    Node *current = head;
    for (size_t i = 1; i < index; ++i)
    {
        current = current->next;
    }
    Node *to_delete = current->next;
    current->next = to_delete->next;
    delete to_delete;

    if (!current->next)
    {
        tail = current;
    }
    num_items--;
    return true;
}

// Find the index
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type &item) const
{
    Node *current = head;
    size_t index = 0;
    while (current)
    {
        if (current->data == item)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

// Return the size of the list
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const
{
    return num_items;
}

// Stack
bool Stack::is_empty() const
{
    return stack.empty();
}

void Stack::push(int value)
{
    stack.push_back(value);
}

void Stack::pop()
{
    if (is_empty())
    {
        throw out_of_range("Stack is empty");
    }
    stack.pop_back();
}

int Stack::top() const
{
    if (is_empty())
    {
        throw out_of_range("Stack is empty");
    }
    return stack.back();
}

double Stack::average() const
{
    if (is_empty())
    {
        throw out_of_range("Stack is empty");
    }
    double sum = accumulate(stack.begin(), stack.end(), 0);
    return sum / static_cast<double>(stack.size());
}

size_t Stack::size() const
{
    return stack.size();
}

// Function to print the contents of the stack
void Stack::print_stack() const
{
    if (is_empty())
    {
        cout << "The stack is empty.\n";
        return;
    }

    cout << "Stack contents (from bottom to top): ";
    for (const int &elem : stack)
    {
        cout << elem << " ";
    }
    cout << endl;
}

// This function ensures that the user enters a valid integer input.
// If the input is invalid (non-integer), it clears the input stream and asks for input again.
int get_valid_input()
{
    int value;
    while (true)
    {
        cin >> value;

        // Check if the input failed (non-integer input).
        if (cin.fail())
        {
            // Clear the error flags on the input stream.
            cin.clear();
            // Ignore any invalid input in the buffer until the next newline.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Prompt the user for a valid integer.
            cout << "Invalid input! Please enter an integer: ";
        }
        else
        {
            // Return the valid integer input.
            return value;
        }
    }
}

int main()
{
    // Create a stack object (based on the custom Stack class).
    Stack myStack;

    int choice; // To store the user's menu choice
    int value;  // To store the integer value the user wants to push to the stack

    do
    {
        // Display the menu options to the user.
        cout << "\n--- Stack Operations ---\n";
        cout << "1. Push a value onto the stack\n";
        cout << "2. Pop a value from the stack\n";
        cout << "3. Check the top of the stack\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Get the average of stack elements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        // Get the user's choice using the input validation function.
        choice = get_valid_input();

        switch (choice)
        {
        // Case 1: Push a value onto the stack
        case 1:
            cout << "Enter a value to push onto the stack: ";
            value = get_valid_input(); // Get the value to be pushed onto the stack
            myStack.push(value);       // Push the value onto the stack
            cout << value << " pushed onto the stack.\n";
            myStack.print_stack();
            break;

        // Case 2: Pop the top value from the stack
        case 2:
            // Check if the stack is not empty
            if (!myStack.is_empty())
            {
                // Pop the top element from the stack
                myStack.pop();
                cout << "Top element popped from the stack.\n";
                myStack.print_stack();
            }
            else
            {
                // If the stack is empty, show an error message
                cout << "Stack is empty. Cannot pop.\n";
            }
            break;

        // Case 3: Show the top value of the stack
        case 3:
            // Check if the stack is not empty
            if (!myStack.is_empty())
            {
                // Display the top element of the stack
                cout << "Top of the stack: " << myStack.top() << endl;
                myStack.print_stack();
            }
            else
            {
                // If the stack is empty, show an error message
                cout << "Stack is empty.\n";
            }
            break;

        // Case 4: Check if the stack is empty
        case 4:
            // If the stack is empty, show an appropriate message
            if (myStack.is_empty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                // If the stack is not empty, show a different message
                cout << "Stack is not empty.\n";
                myStack.print_stack();
            }
            break;

        // Case 5: Calculate and display the average of the stack elements
        case 5:
            // Check if the stack is not empty
            if (!myStack.is_empty())
            {
                myStack.print_stack();
                // Calculate and display the average of the elements in the stack
                cout << "Average of stack elements: " << myStack.average() << endl;
            }
            else
            {
                // If the stack is empty, show an error message
                cout << "Stack is empty. No average to calculate.\n";
            }
            break;

        // Case 6: Exit the program
        case 6:
            // Inform the user that the program is exiting
            cout << "Exiting program.\n";
            break;

        // Default case: Invalid menu option
        default:
            // Inform the user of an invalid choice
            cout << "Invalid choice! Please try again.\n";
        }
        // Keep repeating the menu until the user chooses to exit (choice 6).
    } while (choice != 6);

    return 0;
}