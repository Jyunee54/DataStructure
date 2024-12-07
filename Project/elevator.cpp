#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>

struct Request
{
    int time;
    int from;
    int to;
    bool direction; // true for up, false for down
};

struct Elevator
{
    int currentFloor;
    bool movingUp;
    std::queue<Request, std::deque<Request>> tasks;
};

class ElevatorSystem
{
    std::vector<Elevator> elevators;
    std::queue<Request, std::deque<Request>> pendingRequests;
    int totalFloors;
    std::vector<Request> completedRequests;

public:
    ElevatorSystem(int numElevators, int floors) : totalFloors(floors)
    {
        for (int i = 0; i < numElevators; ++i)
        {
            elevators.push_back({0, true, std::queue<Request, std::deque<Request>>()});
        }
    }

    void addRequest(int time, int from, int to)
    {
        if (from == to)
            return; // Invalid request
        bool direction = (to > from);
        Request req = {time, from, to, direction};
        pendingRequests.push(req);
    }

    void assignRequests()
    {
        while (!pendingRequests.empty())
        {
            Request req = pendingRequests.front();
            pendingRequests.pop();

            // Find the best elevator for the request
            int bestElevator = -1;
            int minDistance = totalFloors + 1;
            for (int i = 0; i < elevators.size(); ++i)
            {
                int distance = abs(elevators[i].currentFloor - req.from);
                if ((elevators[i].movingUp == req.direction || elevators[i].tasks.empty()) &&
                    distance < minDistance)
                {
                    minDistance = distance;
                    bestElevator = i;
                }
            }

            if (bestElevator != -1)
            {
                elevators[bestElevator].tasks.push(req);
            }
            else
            {
                pendingRequests.push(req); // Requeue if no elevator is available
            }
        }
    }

    void stepSimulation(int currentTime)
    {
        for (auto &elevator : elevators)
        {
            if (!elevator.tasks.empty())
            {
                Request req = elevator.tasks.front();

                if (elevator.currentFloor == req.from)
                {
                    std::cout << "Time " << currentTime << ": Request from Floor " << req.from << " to Floor " << req.to << " started.\n";
                    elevator.tasks.pop();
                    completedRequests.push_back(req);
                    elevator.currentFloor = req.to;
                }
                else
                {
                    elevator.currentFloor += elevator.movingUp ? 1 : -1;
                }

                elevator.movingUp = req.to > elevator.currentFloor;
            }
        }
    }

    void printStatus()
    {
        for (int i = 0; i < elevators.size(); ++i)
        {
            std::cout << "Elevator " << i + 1 << ": Floor " << elevators[i].currentFloor;
            if (!elevators[i].tasks.empty())
            {
                std::cout << " -> Next: Floor " << elevators[i].tasks.front().to;
            }
            std::cout << "\n";
        }
    }
};

void simulateElevatorSystem()
{
    const int numElevators = 3;
    const int totalFloors = 10;
    const int simulationTime = 20;

    ElevatorSystem system(numElevators, totalFloors);
    srand(static_cast<unsigned>(time(0)));

    for (int t = 0; t < simulationTime; ++t)
    {
        if (rand() % 3 == 0)
        { // Randomly generate new requests
            int from = rand() % totalFloors;
            int to = rand() % totalFloors;
            system.addRequest(t, from, to);
        }

        system.assignRequests();
        system.stepSimulation(t);

        std::cout << "Time: " << t << "\n";
        system.printStatus();
        std::cout << "=====================" << "\n";
    }
}

int main()
{
    simulateElevatorSystem();
    return 0;
}
