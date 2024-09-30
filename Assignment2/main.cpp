#include "header.h"
#include <limits>

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
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

// Return item back of the list
template <typename Item_Type>
const Item_Type &Single_Linked_List<Item_Type>::back() const
{
    if (empty())
    {
        throw std::out_of_range("List is empty");
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
        throw std::out_of_range("Stack is empty");
    }
    stack.pop_back();
}

int Stack::top() const
{
    if (is_empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return stack.back();
}

double Stack::average() const
{
    if (is_empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    double sum = std::accumulate(stack.begin(), stack.end(), 0);
    return sum / static_cast<double>(stack.size());
}

size_t Stack::size() const
{
    return stack.size();
}

// This function ensures that the user enters a valid integer input.
// If the input is invalid (non-integer), it clears the input stream and asks for input again.
int get_valid_input()
{
    int value;
    while (true)
    {
        std::cin >> value;

        // Check if the input failed (non-integer input).
        if (std::cin.fail())
        {
            // Clear the error flags on the input stream.
            std::cin.clear();                                                   // 실패 상태 플래그를 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 잘못된 입력을 버림
            std::cout << "Invalid input! Please enter an integer: ";
        }
        else
        {
            return value; // 올바른 정수 값이면 반환
        }
    }
}

int main()
{
    // Create a stack object
    Stack myStack;

    int choice;
    int value;

    do
    {
        // 메뉴 출력
        std::cout << "\n--- Stack Operations ---\n";
        std::cout << "1. Push a value onto the stack\n";
        std::cout << "2. Pop a value from the stack\n";
        std::cout << "3. Check the top of the stack\n";
        std::cout << "4. Check if stack is empty\n";
        std::cout << "5. Get the average of stack elements\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        choice = get_valid_input(); // 메뉴 선택 입력

        switch (choice)
        {
        case 1:
            std::cout << "Enter a value to push onto the stack: ";
            value = get_valid_input(); // 스택에 넣을 값 입력
            myStack.push(value);
            std::cout << value << " pushed onto the stack.\n";
            break;

        case 2:
            if (!myStack.is_empty())
            {
                myStack.pop();
                std::cout << "Top element popped from the stack.\n";
            }
            else
            {
                std::cout << "Stack is empty. Cannot pop.\n";
            }
            break;

        case 3:
            if (!myStack.is_empty())
            {
                std::cout << "Top of the stack: " << myStack.top() << std::endl;
            }
            else
            {
                std::cout << "Stack is empty.\n";
            }
            break;

        case 4:
            if (myStack.is_empty())
            {
                std::cout << "Stack is empty.\n";
            }
            else
            {
                std::cout << "Stack is not empty.\n";
            }
            break;

        case 5:
            if (!myStack.is_empty())
            {
                std::cout << "Average of stack elements: " << myStack.average() << std::endl;
            }
            else
            {
                std::cout << "Stack is empty. No average to calculate.\n";
            }
            break;

        case 6:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}