/*
Problem Link: 


Certainly! Let's break down the thought process, intuition, and complexities for solving the LeetCode problem 91 - Decode Ways.

Problem Intuition:

1. Recursive Solution:
   - Start with a recursive approach to break down the problem into subproblems.
   - At each step, consider whether decoding the current digit individually or with the next one is a valid option.
   - Base case: If the end of the string is reached, return 1.
   - Handle cases where a '0' is encountered (no decoding possible with '0').

2. Memoization Solution:
   - Recognize the repeating subproblems in the recursive solution.
   - Use memoization to store the results of subproblems to avoid redundant calculations.
   - Check the memo table before making recursive calls to utilize precomputed results.

3. Tabulation Solution:
   - Translate the memoized solution into a bottom-up dynamic programming approach.
   - Utilize an array (`dp`) to store solutions for subproblems iteratively.
   - Start solving from the end of the string, building up solutions for smaller subproblems.

Time Complexity:

1. Recursive Solution:
   - Exponential time complexity due to repeated calculations of overlapping subproblems.
   - O(2^n), where n is the length of the input string.

2. Memoization Solution:
   - Memoization reduces time complexity by storing previously computed results.
   - O(n), where n is the length of the input string.

3. Tabulation Solution:
   - Iterative bottom-up approach ensures linear time complexity.
   - O(n), where n is the length of the input string.

### Space Complexity:

1. Recursive Solution:
   - Uses the call stack for recursive calls, leading to potential stack overflow for large inputs.
   - O(n), where n is the length of the input string (considering the depth of the recursion).

2. Memoization Solution:
   - Requires additional space for the memo table.
   - O(n), where n is the length of the input string.

3. Tabulation Solution:
   - Utilizes a single array for storing solutions, leading to optimal space usage.
   - O(n), where n is the length of the input string.

### Conclusion:

Solving the problem involved transitioning from a naive recursive approach to optimized dynamic programming solutions.
The final tabulation solution offers both optimal time and space complexity, providing an efficient way to decode the given string.
Understanding the problem's structure, identifying repeating subproblems, and leveraging dynamic programming concepts were crucial in devising an efficient solution.


/******************************************************************************************************/

//Recursive code got TLE

class Solution {
public:
    int solve(int i, string &s, int n) {
        if(i == n)
        return 1;

        if(s[i] == '0') {
            return 0;
        }

        int result = solve(i+1, s, n);

        if(i+1 < n) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <='6')) {
                result += solve(i+2, s, n);
            }
        }
        return result;
    }
    int numDecodings(string s) {
        int n = s.length();

        return solve(0, s, n);
    }
};

//Memoization Approach

class Solution {
public:
    int solve(int i, string &s, int n, vector<int> &dp) {
        if(i == n)
        return dp[i] = 1;

        if(dp[i] != -1)
        return dp[i];

        if(s[i] == '0') {
            return dp[i] = 0;
        }

        int result = solve(i+1, s, n, dp);

        if(i+1 < n) {
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <='6')) {
                result += solve(i+2, s, n, dp);
            }
        }
        return dp[i] = result;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);

        return solve(0, s, n, dp);
    }
};

//Tabulation Approach

class Solution {
public:
    int solve(int i, string &s, int n, vector<int> &dp) {
        //simply simulate the memoized version
        //t[i] = ways to decode string from index i to n
        dp[n] = 1;
        
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '0')
                dp[i] = 0;
            else {
                dp[i] = dp[i+1];
                if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);

        return solve(0, s, n, dp);
    }
};

/******************************************************************************************************/

