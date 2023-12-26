/*

Recursive Solution:
Intuition: Dive headfirst into the dice-roll universe, exploring all possible outcomes. A simple yet exhaustive approach, but beware of the expanding recursive tree.

Thought Process: For each die, exhaustively consider every face, tracking the ways to reach the target sum. However, the repetition of subproblems becomes the Achilles' heel.



Memoized Solution:
Intuition: Equip yourself with a map to navigate the dice-roll landscape efficiently. Memorize previous findings, reducing redundancy and steering clear of time constraints.

Thought Process: Cache the results of subproblems, steering clear of the tangled recursive web. A leap toward efficiency, transforming the maze into a structured path.



Tabulation Solution:
Intuition: Construct a dynamic matrix, systematically filling in possibilities and transcending recursive constraints. The journey becomes about efficient bottom-up construction.

Thought Process: Roll up your sleeves for dynamic programming mastery. Construct a matrix, iteratively updating possibilities, optimizing both time and space.



/******************************************************************************************************/

//Recursive code got TLE

class Solution {
public:
    long M = 1e9 + 7;
    int solve(int n, int k, int target) {
        if(target < 0)
            return 0;

        if(n == 0)
            return target == 0;
        
        int ways = 0;
        
        for(int i = 1; i <= k; i++) {
            ways += solve(n-1, k, target-i);
            ways %= M;
        }
        
        return ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};

//Memoization Approach

class Solution {
public:
    long M = 1e9 + 7;
    int solve(int n, int k, int target, vector<vector<int>> &dp) {
        if(target < 0)
            return 0;

        if(n == 0)
            return target == 0;
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int ways = 0;
        
        for(int i = 1; i <= k; i++) {
            ways += solve(n-1, k, target-i, dp);
            ways %= M;
        }
        
        return dp[n][target] = ways;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};

//Tabulation Approach

class Solution {
public:
    long M = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> t(n+1, vector<int>(target+1));
        
        //t[i][j] = total ways to obtain j from exactly i dices
        
        t[0][0] = 1; 
        /*
            if(n == 0 && target == 0) we have found the target with all dices
            Or, understand it like this : 
            To obtain target 0 with 0 dices, how many ways  : 1
        */
        
        for(int i = 1; i <= n; i++) { //coin size loop (from coin change-2)
            for(int j = 1; j<= target; j++) { //target loop (from coin change-2)
                
                //Now since coin (here dice) has faces, so we need a loop for that too
                for(int f = 1; f <= k; f++) {
                    //face value should be always <= target
                    //so,
                    if(f <= j) {
                        t[i][j] = (t[i][j] + t[i-1][j-f])%M;
                    }
                }
            }
        }
        
        return t[n][target];
        
    }
};

/******************************************************************************************************/



/*

Recursive (TLE):

Time complexity: O(k^n), leading to Time Limit Exceeded for larger inputs.
Space complexity: O(n) due to recursion stack.


Memoized (Optimized):

Time complexity: O(n * target * k).
Space complexity: O(n * target) for memoization table.


Tabulation (Iterative):

Time complexity: O(n * target * k).
Space complexity: O(n * target) for DP table.

*/

