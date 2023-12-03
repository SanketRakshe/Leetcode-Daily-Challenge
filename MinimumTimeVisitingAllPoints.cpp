/*
Problem Link: https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2023-12-03
*/

/*
Intuition:
The key insight here is to realize that to minimize the time,
you should move diagonally as much as possible since it's the most efficient way to cover distance.
Therefore, for each pair of consecutive points, you should move diagonally until you reach either the same x-coordinate or the same y-coordinate,
and then move vertically or horizontally to the next point.
*/


/*
Algorithm:

1. Iterate through each pair of consecutive points in the input array.

2. Calculate the horizontal distance (dx) and vertical distance (dy) between each pair of points.

3. Find the minimum of dx and dy (the diagonal distance) and add it to the total time.

4. Find the absolute difference between dx and dy (remaining distance) and add it to the total time.

5. Repeat this process for all pairs of points.

6. The sum of these distances will give you the minimum time required to visit all points.

*/


/*
Learning from the problem :
1. Greedy Approach: The algorithm follows a greedy approach by choosing the diagonal move whenever possible, as it minimizes the total time.

2. Understanding Constraints: The constraints help you understand the input size and guide you to choose an algorithm with reasonable time and space complexity.

*/


/******************************************************************************************************/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(); // Number of points
        int steps = 0; // Variable to store the total time

        // Iterate through each pair of consecutive points
        for (int i = 0; i < n - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            // Calculate the horizontal and vertical distances
            int dx = std::abs(x2 - x1);
            int dy = std::abs(y2 - y1);

            // Find the minimum of dx and dy (diagonal distance)
            int diagonal = std::min(dx, dy);

            // Find the absolute difference between dx and dy (remaining distance)
            int remain = std::abs(dx - dy);

            // Add the diagonal and remaining distances to the total time
            steps += diagonal + remain;
        }
        return steps; // Return the minimum time to visit all points
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
The algorithm iterates through each pair of consecutive points once, performing constant time operations for each pair.
Therefore, the time complexity is O(n), where n is the number of points.

Space Complexity:
The algorithm uses a constant amount of space for variables regardless of the input size. Thus, the space complexity is O(1).
*/