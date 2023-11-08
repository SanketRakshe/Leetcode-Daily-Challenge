/*
Problem Link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/?envType=daily-question&envId=2023-11-08
*/

/*

Intuition:

Hi there, 😄

The problem involves navigating a 2D grid from a starting point to a target point in a certain amount of time while following the rule of moving to adjacent cells each second.
The goal is to determine if it's possible to reach the target within the given time limit. To solve this,
we calculate the vertical and horizontal distances between the start and target cells and compare these distances with the given time constraint.
If the time is sufficient to cover the longer of the two distances, the answer is "true," otherwise, it's "false."

*/

/*

Learning from the problem :

The problem involves navigating a 2D grid from a starting point to a target point in a certain amount of time while following the rule of moving to adjacent cells each second.
The goal is to determine if it's possible to reach the target within the given time limit.
To solve this, we calculate the vertical and horizontal distances between the start and target cells and compare these distances with the given time constraint.
If the time is sufficient to cover the longer of the two distances, the answer is "true," otherwise, it's "false."

*/




/******************************************************************************************************/

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Calculate the vertical and horizontal distances between the start and target cells.
        int verticalDist = abs(sy - fy);
        int horizontalDist = abs(sx - fx);

        // If we start and end at the same cell, we need at least 1 second to stay there.
        if(verticalDist == 0 && horizontalDist == 0 && t == 1) {
            return false;
        }

        // To reach the target cell, we need to cover the maximum of verticalDist and horizontalDist
        // because moving diagonally takes the same time as moving horizontally or vertically.
        int maxDist = max(verticalDist, horizontalDist);

        // If t is greater than or equal to maxDist, it is possible to reach the target cell in t seconds.
        return t >= maxDist;
    }
};


/******************************************************************************************************/

/*

Complexity
Time complexity: 
The time complexity of this solution is O(1) because it performs a few simple mathematical calculations and comparisons.
The input size does not affect the time complexity.


Space Complexity:
The space complexity is O(1) as well because the solution does not use any additional data structures that depend on the input size.
*/