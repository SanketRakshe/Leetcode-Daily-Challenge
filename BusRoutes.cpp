/*
Problem Link: https://leetcode.com/problems/bus-routes/?envType=daily-question&envId=2023-11-12
*/

/*
Intuition:

The problem involves finding the least number of buses needed to travel from a source bus stop to a target bus stop.
The buses and stops are represented as a graph, where each bus route is a node, and each bus stop is connected to the bus routes it belongs to.
We need to perform a Breadth-First Search (BFS) to find the minimum number of buses needed.
*/

/*
Algorithm:

1. Build Graph:
   - Create an adjacency list where each bus stop is a key, and the value is a list of bus routes that pass through that stop.

2. BFS:
   - Start from the source bus stop.
   - Initialize a queue and a visited array.
   - Add all the routes passing through the source stop to the queue and mark them as visited.
   - Perform BFS:
      - For each route in the queue, visit each stop on that route.
      - If the target stop is found, return the number of buses taken so far.
      - If a stop is not visited, mark it as visited, and add all the routes passing through that stop to the queue.

3. Result:
   - If the target is not reached, return -1.
*/

/*
Learning from the problem :

This problem involves modeling the bus routes and stops as a graph and using BFS to find the shortest path.
It teaches how to build a graph based on the problem requirements and efficiently perform BFS to find the minimum number of steps.

*/




/******************************************************************************************************/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        
        // Step 1: Build Graph
        unordered_map<int, vector<int>> adj;
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop : routes[route]) {
                adj[stop].push_back(route);
            }
        }
        
        // Step 2: BFS
        queue<int> que;
        vector<bool> visited(501, false);  // Assuming the maximum number of stops is 501
        
        // Add all routes passing through the source stop to the queue
        for (auto route : adj[source]){
            que.push(route);
            visited[route] = true;
        }
        
        int busCount = 1;
        while (!que.empty()) {
            int size = que.size();
            while(size--) {
                int route = que.front();
                que.pop();
                
                // Check each stop on the current route
                for (auto &stop: routes[route]) {
                    if (stop == target) {
                        return busCount;  // Target stop found
                    }
                    // Add routes passing through the current stop to the queue
                    for (auto nextRoute : adj[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;  // Move to the next bus
        }
        
        return -1;  // Target not reached
    }
};

/******************************************************************************************************/

/*

Complexity
Time complexity: 
The time complexity is O(N + R) where N is the total number of stops and R is the total number of routes.
This is because we build the graph with all the stops and routes.

Space Complexity:
The space complexity is O(N + R) for storing the adjacency list and the visited array.
*/