/*
Problem Link: https://leetcode.com/problems/seat-reservation-manager/?envType=daily-question&envId=2023-11-06
*/

/*

Intuition:

Hi there, 😄

Let's dive🤿 deep into our today's problem.

The SeatManager class is designed to manage seat reservations in a system with a specific number of seats,
denoted as 'n.' It maintains a priority queue (min-heap) to keep track of seat availability.
When a user requests to reserve a seat, the class provides the smallest unreserved seat,
and when a user unreserves a seat, the seat becomes available again.
The goal is to efficiently allocate seats and maintain availability.

*/




/******************************************************************************************************/

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=1; i<=n; i++)
        pq.push(i);
    }
    
    int reserve() {
        if(!pq.empty()) {
            auto seat = pq.top();
            pq.pop();
            return seat;
        }
        return -1;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */


/******************************************************************************************************/

/*

Complexity
Time complexity: 
1) SeatManager Constructor (SeatManager(int n)):
The constructor initializes the priority queue with seat numbers from 1 to 'n,'
which requires inserting 'n' elements into the priority queue.
Each insertion operation takes O(logn) time in a priority queue,
resulting in a total time complexity of O(n∗logn).

2) reserve Method:
The reserve method performs a single operation on the priority queue,
which is either polling the smallest element O(logn) or
checking if the queue is empty O(1). In the worst case, it is O(logn).
Space complexity: O(1)

3)unreserve Method:
The unreserve method performs a single operation on the priority queue,
which is adding an element (seat number) back to the queue.
This operation takes O(logn) time in the worst case.
Since we are using constant variables.


Space Complexity:

1)SeatManager Constructor (SeatManager(int n)):
The space complexity of the constructor is determined by the size of the priority queue.
It stores 'n' seat numbers,
resulting in a space complexity of O(n)

2)reserve Method:
The reserve method does not allocate any additional space that scales with the input 'n.'
It only returns the seat number, so it has a constant space complexity.

3)unreserve Method:
Similar to the reserve method, the unreserve method does not require additional space that scales with 'n.'
It simply adds a seat number back to the priority queue.
*/