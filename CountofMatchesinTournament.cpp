/*
Problem Link: https://leetcode.com/problems/count-of-matches-in-tournament/?envType=daily-question&envId=2023-12-05
*/

/*
Intuition:
The problem essentially asks for the total number of matches played in a tournament based on the given rules.
The rules state that if the current number of teams is even, each team gets paired, and half of them advance.
If the current number is odd, one team randomly advances, and the rest get paired, with one extra team advancing.
The goal is to find the total number of matches played until there is a winner.

*/


/*
Algorithm:
The algorithm takes advantage of the fact that in each round, half of the teams get eliminated,
either through direct pairing or by one team advancing directly. Therefore, the total number of matches is equal to the total number of teams minus one.

1. The algorithm subtracts 1 from the given input `n` and returns the result.
*/


/*
Learning from the problem :
The key insight is that regardless of whether the number of teams is even or odd, in each round, half of the teams get eliminated.
This leads to a straightforward formula for calculating the total number of matches.

*/


/******************************************************************************************************/

class Solution {
public:
    int numberOfMatches(int n) {
        //The total number of matches is equal to the total number of teams minus one
        //This is because in each round, half of the teams get eliminated
        return n - 1;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
The time complexity of the solution is constant O(1) because the algorithm performs a simple arithmetic operation (subtraction) regardless of the input size.

Space Complexity:
The space complexity is also O(1) since the algorithm uses a constant amount of space to store the input and the result.

*/