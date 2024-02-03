/*
Problem Intuition:

- The goal is to maximize the overall sum of the array after partitioning it into subarrays with a maximum length of `k`.
- Each subarrays elements are replaced with the maximum value within that subarray.
- This implies that we want to strategically group larger numbers together to maximize the contribution of each subarray to the final sum.

Thought Process and Algorithm:

1. Dynamic Programming (DP) Approach:
   - Recognize that overlapping subproblems exist (e.g., calculating the maximum sum for a subarray starting at index 3 might rely on results for subarrays starting at 4 or 5).
   - Employ DP to store calculated results and avoid redundant computations.

2. Recursive Function with Memoization:
   - `solveMem(ind, k, n, arr, dp)` calculates the maximum sum achievable starting from index `ind`, considering a maximum subarray length of `k`.
   - Base Case:** If `ind` is beyond the arrays end, return 0 (no elements left).
   - Memoization: If the result for `ind` is already calculated, return it from `dp`.
   - Iteration and Recursion:
     - Iterate through potential subarrays starting at `ind` with lengths up to `k`.
     - Track the current maximum value within the subarray.
     - Recursively call `solveMem` for the remaining portion of the array.
     - Calculate the potential maximum sum for the current subarray and update the overall maximum `ans`.
   - Return the maximum `ans` and store it in `dp` for future use.
*/

//Code:

class Solution {
public:
    int solveMem(int ind, int k, int n, vector<int>& arr, vector<int>& dp) {
        if(ind >= n)
        return 0;

        int ans = 0;
        int currMax = INT_MIN;

        if(dp[ind] != -1) return dp[ind];

        for(int i=ind; i<n && i-ind+1 <= k; i++) {
            currMax = max(currMax, arr[i]);

            ans = max(ans, currMax * (i-ind+1) + solveMem(i+1, k, n, arr, dp));
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);

        return solveMem(0, k, n, arr, dp);
    }
};


/*
**Time and Space Complexity:**

- **Time Complexity:** O(n * k) due to nested loops and recursive calls.
- **Space Complexity:** O(n) for the DP array `dp`.
*/

