/*
Problem Link: https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05
*/

/*

Intuition:

Hi there, 😄

Let's dive🤿 deep into our today's problem.

The problem involves simulating a game between two integers in the array, where the larger integer wins and the smaller one moves to the end.
We need to find the integer that wins k consecutive rounds.

*/


/*
Learning from the problem:

Through this problem, I've learned how to determine the winner in a game where two distinct integers compete based on a set of rules.
This experience has provided valuable insights into efficiently handling edge cases, such as when the number of rounds (k) is substantial relative to the array size or when the maximum element in the array is the clear winner.
My solution effectively tracks the current winner and the number of consecutive wins, enabling optimization by avoiding unnecessary comparisons.

*/



/******************************************************************************************************/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxElement = *max_element(begin(arr), end(arr));

        if(k >= n) 
        return maxElement;

        int winner = arr[0];
        int wins = 0;

        for(int i=1; i<n; i++) {
            if(winner > arr[i]) {
                wins++;
            }
            else {
                winner = arr[i];
                wins = 1;
            }

            if(wins == k || winner == maxElement) 
            return winner;
        }
        return winner;
    }
};


/******************************************************************************************************/

/*

Time complexity: O(N)
It iterates through the array of length 'n' once.

Space complexity: O(1) 
It uses a constant amount of additional space regardless of the input size,
as it only uses a few integer variables to keep track of the current winner and consecutive wins.

*/