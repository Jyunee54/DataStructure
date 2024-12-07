# Elevator Request Handling System Report

## 1. Assumptions (Optional)

- The elevator handles requests one at a time and operates in a single-building environment.
- Requests are always valid (i.e., pickup and destination floors are within the building range).
- The elevator operates sequentially and does not handle concurrent requests simultaneously.
- The building has a fixed number of floors (e.g., 10 floors).
- The system only considers one elevator, though the design could be extended to support multiple elevators.

## 2. UML Class Diagram

+----------------------+  
|      Elevator        |  
+----------------------+  
| - currentFloor: int  |  
| - direction: string  |  
| - upRequests: PQ<int>|  
| - downRequests: PQ<int>|  
+----------------------+  
| + addRequest(pickup: int, dest: int) |  
| + processRequests()                  |  
+----------------------+  


+----------------------+  
|       Request        |  
+----------------------+  
| - pickupFloor: int   |  
| - destinationFloor: int|  
| - time: int          |  
+----------------------+  


**Explanation:**

- `Elevator` Class: Manages the elevator operations, current floor, and direction. Handles requests using priority queues.
- `Request` Struct: Represents each user request with pickup floor, destination floor, and request time.

## 3. Efficiency of Algorithms

### Significant Functions and Their Big-O Complexity

1. addRequest(int pickupFloor, int destinationFloor)

   - **Complexity**: O(log N)
   - **Explanation**: Adding an element to a priority queue (either upRequests or downRequests) takes O(log N) time.

2. processRequests()

   - Complexity: O(N log N)
   - Explanation: Processing all the requests involves repeatedly extracting the minimum or maximum element from the priority queues, each operation taking O(log N). If there are N requests, the overall complexity is O(N log N).

### Possible Improvements

- The current implementation processes requests sequentially. To improve efficiency, a more sophisticated scheduling algorithm could be used, such as a lookahead approach or optimizing for shortest seek time first (SSTF).

## 4. References
- Textbook: "Data Structures and Algorithm Analysis in C++," Chapter 10, Page 381.
- C++ Documentation: cplusplus.com - Priority Queue
- GitHub Guide: GitHub Docs