/*
Problem Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=daily-question&envId=2023-12-21


Problem Understanding:
The problem asks for finding the widest vertical area between two points such that no other points lie inside this area. The width of the vertical area is determined by the difference in x-coordinates of two points. The task is to find the maximum such width.

Thought Process:
1. Sorting:
   - Sorting the points based on their x-coordinates helps in finding adjacent points easily.
   - Once sorted, we can iterate through the sorted points to find the maximum width.

2. Finding Width:
   - Iterate through the sorted points.
   - Calculate the difference in x-coordinates between the current point and the previous point.
   - Keep track of the maximum width encountered so far.



Algorithm:

1. Sort the points based on x-coordinates.
2. Initialize a variable `ans` to 0 to keep track of the maximum width.
3. Iterate through the sorted points.
   - Calculate the width between the current point and the previous point.
   - Update `ans` if the calculated width is greater than the current maximum width.
4. Return the final maximum width.




Learning from the problem :

- Sorting the points based on a coordinate is a common technique for solving problems related to intervals or ranges.
- The key idea is to utilize the order of the points to simplify the problem.


/******************************************************************************************************/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Sorting points based on x-coordinates
        sort(points.begin(), points.end());

        // Initialize variable to keep track of maximum width
        int ans = 0;

        // Iterate through sorted points
        for(int i=1; i<points.size(); i++) {
            // Calculate width between current and previous point
            int width = points[i][0] - points[i-1][0];
            
            // Update maximum width if the calculated width is greater
            ans = max(ans, width);
        }
        return ans;
    }
};



/******************************************************************************************************/

/*

Complexity
Time Complexity: O(nlogn)

Space Complexity: O(1)


*/