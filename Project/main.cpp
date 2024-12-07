#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Structure
struct Request
{
    int pickupFloor;      // The floor where the user calls the elevator
    int destinationFloor; // The floor where the user wants to go
    int time;             // The time when the request is made
};

// Elevator class to handle requests
class Elevator
{
private:
    int currentFloor;                                          // The current floor of the elevator
    string direction;                                          // The current direction ("UP" or "DOWN")
    priority_queue<int, vector<int>, greater<int>> upRequests; // Min-heap for upward requests
    priority_queue<int> downRequests;                          // Max-heap for downward requests

public:
    // Constructor to initialize the elevator
    Elevator() : currentFloor(0), direction("UP") {}

    // Function to add a request to the appropriate queue
    void addRequest(int pickupFloor, int destinationFloor)
    {
        if (pickupFloor > currentFloor)
        {
            upRequests.push(pickupFloor);
        }
        else
        {
            downRequests.push(pickupFloor);
        }
    }

    // Function to process the requests and move the elevator
    void processRequests()
    {
        while (!upRequests.empty() || !downRequests.empty())
        {
            if (direction == "UP" && !upRequests.empty())
            {
                // Move the elevator to the next upward request
                currentFloor = upRequests.top();
                upRequests.pop();
                cout << "Elevator moved UP to floor: " << currentFloor << endl;
            }
            else if (!downRequests.empty())
            {
                // Change direction to DOWN and process downward requests
                direction = "DOWN";
                currentFloor = downRequests.top();
                downRequests.pop();
                cout << "Elevator moved DOWN to floor: " << currentFloor << endl;
            }
            else
            {
                // If no requests are left, default back to UP direction
                direction = "UP";
            }
        }
    }
};

int main()
{
    Elevator elevator;

    // Adding example requests
    elevator.addRequest(2, 5);
    elevator.addRequest(4, 1);
    elevator.addRequest(3, 6);

    // Process all the requests
    elevator.processRequests();

    return 0;
}