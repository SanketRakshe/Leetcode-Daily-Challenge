/*
Problem Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/?envType=daily-question&envId=2023-11-11
*/

/*

Intuition:

Hi there, 😄

Let's dive🤿 deep into our today's problem.

The problem requires implementing a class `Graph` to represent a directed weighted graph and providing methods to initialize the graph, add edges,
and find the shortest path between two nodes using Dijkstra's algorithm. Dijkstra's algorithm is a popular
algorithm for finding the shortest path in a graph with non-negative edge weights.

*/

/*

**Algorithm:**
1. The `Graph` class is initialized with a given number of nodes `n` and a list of edges `edges`. The edges are stored in an adjacency list representation using an unordered map.
2. The `addEdge` method is used to add a new edge to the graph. The edge information is added to the adjacency list.
3. The `shortestPath` method calculates the shortest path between two given nodes using Dijkstra's algorithm. It returns the minimum cost of the path.
4. The `dijkstra` method performs Dijkstra's algorithm. It maintains a priority queue to process nodes with the smallest tentative distance first. The algorithm continues until all nodes are processed or the destination node is reached.
5. The tentative distance to each node is updated if a shorter path is found.
6. If the destination node is reached, the minimum cost to reach it is returned; otherwise, -1 is returned, indicating that there is no path.

*/

/*

Learning:
- Dijkstra's algorithm is a versatile algorithm for finding the shortest path in a graph with non-negative edge weights.
- Priority queues are useful for efficiently selecting nodes with the smallest tentative distances during the algorithm's 
  execution.
- Properly updating distances and using suitable data structures for graph representation are crucial for the efficiency
  of the algorithm.

*/

/******************************************************************************************************/

class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>adj;
    int total_nodes = 0;
    typedef pair<int, int> p;

    // Constructor to initialize the graph with nodes and edges
    Graph(int n, vector<vector<int>>& edges) {
        for(auto it:edges ) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        total_nodes = n;
    }
    
    // Method to add a new edge to the graph
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        total_nodes++;
    }
    
    // Method to find the shortest path between two nodes
    int shortestPath(int node1, int node2) {
        return dijkstra(total_nodes, node1, node2);
    }

private:
    // Dijkstra's algorithm to find the shortest path
    int dijkstra(int V, int source , int destination){
        // Initialize distances to all nodes as infinity
        vector<int> distTo(V , 1e9);

        // Priority queue to process nodes with the smallest tentative distances first
        priority_queue<p, vector<p>, greater<p>> pq;

        // Set distance to source node as 0 and push it into the priority queue
        distTo[source] = 0;
        
        pq.push({source, 0});  

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.first;
            int distance = it.second;

            pq.pop();

            // Explore neighbors of the current node
            for(auto it:adj[node]){
                int newNode = it.first;
                int weight =  it.second;

                //If a shorter path is found, update the distance and push into the priority queue
                if(distance+weight < distTo[newNode]){
                    distTo[newNode] = distance+weight;

                    pq.push({newNode , distance+weight});
                }
            }
        }
        // If the destination node is reached, return the minimum cost; otherwise, return -1
        return ((distTo[destination] == 1e9) ? -1 : distTo[destination]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */


/******************************************************************************************************/

/*

Complexity
Time Complexity:
- The time complexity of Dijkstra's algorithm is O((V + E) * log(V)), where V is the number of nodes and E
  is the number of edges.
- Each edge is processed once, and the priority queue operations take O(log(V)) time.

Space Complexity:
- The space complexity is O(V + E), where V is the number of nodes and E is the number of edges.
- The adjacency list representation requires O(V + E) space, and additional space is used for the priority queue and distance array.
*/