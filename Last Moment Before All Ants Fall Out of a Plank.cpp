/*
Problem Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/?envType=daily-question&envId=2023-11-04
*/

/*

Intuition:

Hi there, 😄

Let's dive🤿 deep into our today's problem.

The task today is to examine the behaviour of a group of friendly ants. Given that they are on a wooden board and each ant is going left or right,
we want to calculate the time it takes them to fell of the board.
But what happens when two ants hit eachother ?🤔
in this case, they reverse their direction in no time -they collide-.
Noting that collision doesn't take time.

*/

/*

The primary takeaway from this problem is realizing the straightforward approach to calculating the moment of the last collision in a scenario where particles are approaching each other from opposite directions.
By examining the initial positions of particles on both sides and selecting the maximum position among those moving to the left and the maximum distance traveled by a particle on the right,
the algorithm effectively pinpoints the precise moment of the final collision. 
This highlights the elegance of a simple yet effective solution to a seemingly complex scenario.

*/



/******************************************************************************************************/

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int latsFallTime = 0;
        
        //Find the maximum position reached by ants moving to the left.
        for(auto leftPosition: left) {
            latsFallTime = max(latsFallTime, leftPosition);
        }

        //Find the maximum position reached by ants moving to the right, 
        //accounting for their starting positions from the right end of the plank (n - position).
        for(auto rightPosition: right) {
            latsFallTime = max(latsFallTime, n - rightPosition);
        }

        return latsFallTime;
    }
};


/******************************************************************************************************/

/*

Complexity
Time complexity: O(N)
Since we are only using two for loops to traverse over the arrays and the lengths of the two arrays are maximum N then time complexity is O(N).
Space complexity: O(1)
Since we are using constant variables.

*/