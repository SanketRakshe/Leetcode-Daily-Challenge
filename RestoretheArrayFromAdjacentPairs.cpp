/*
Problem Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/?envType=daily-question&envId=2023-11-10
*/

/*

Intuition:

Hi there, 😄

The problem revolves around reconstructing an array given information about adjacent pairs of elements.
The intuition lies in treating the array as a graph, where each element is a node, and the adjacent pairs represent edges.
By using a depth-first search (DFS) traversal starting from a node with only one adjacent element,
we can reconstruct the original order of the elements.

*/

/*

Algorithm:

1) Build Adjacency List:
Create an unordered map, adj, to represent the adjacency list. Iterate through the given adjacentPairs and populate the adjacency list,
considering both directions (undirected graph).

2)Identify Start Point:
Find the starting point for the DFS traversal. Iterate through the adjacency list and identify a node with only one adjacent element.
This node will be the starting point for the DFS.

3)DFS Traversal:
Implement a depth-first search function (dfs) that takes a node, the previous node, and the adjacency list as parameters.
During the DFS, add each visited node to the result vector.
Ensure that the traversal does not revisit the previous node to avoid cycles.

4)Result:
The result vector contains the order of elements obtained from the DFS traversal. This represents the reconstructed original array.

*/

/*

Learning from the problem :

This problem emphasizes the utility of graph representation for array reconstruction,
utilizing DFS for efficient traversal. The strategic identification of a starting point with a single adjacent element
demonstrates optimization in algorithm design. It underscores the versatility of DFS,
not only for graph exploration but also for reconstructing original sequences,
showcasing the synergy between graph theory and array reconstruction challenges.

*/




/******************************************************************************************************/

class Solution {
    public:vector<int> result;

    // Depth-first search function
    void dfs(int u, int prev, unordered_map<int, vector<int>> &adj) {
        result.push_back(u);

        // Traverse through adjacent elements
        for(auto v: adj[u]) {
            if(v != prev) {
                dfs(v, u, adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;

        // Build adjacency list
        for(auto it: adjacentPairs) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int startPoint = -1;

        // Find the start point with only one adjacent element
        for(auto it: adj) {
            if(it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }

        // Perform DFS traversal
        dfs(startPoint, INT_MIN, adj);

        return result;
    }
};


/******************************************************************************************************/

/*

Complexity
Time complexity: 
O(N), where N is the number of elements in the array. Each element is visited once during the DFS traversal.

Space Complexity:
O(N), where N is the number of elements in the array. This accounts for the space required for the result vector and the adjacency list.
*/