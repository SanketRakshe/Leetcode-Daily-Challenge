/* 
Intuition and Thought Processes:

Key Idea: The longest increasing subsequence (LIS) for a given element can be built upon the LIS ending at previous elements.

Recursive Approach:
- Base Cases: If we've reached the end of the array or a negative index, return 0 (no LIS possible).
- Recursive Cases:
    - Include Current Element: If the current element is larger than the previous element (maintaining increasing order), consider including it in the LIS. Calculate the LIS by including the current element and adding 1 to the LIS ending at the previous element.
    - Exclude Current Element: Exclude the current element and continue exploring LIS ending at the previous element.
- Return the maximum of both cases to find the optimal LIS ending at the current position.

Memoization:
- Store previously calculated results in a 2D array `dp` to avoid redundant calculations, significantly reducing time complexity.

-Tabulation (Bottom-Up) Approach:
- Initialization: Create a `dp` array where `dp[i]` represents the LIS ending at index `i`. Initialize all elements to 1 (each element can form an LIS of length 1 with itself).
- Iteration:
    - Iterate through the array, comparing each element with previous elements.
    - If the current element is larger than a previous element, update `dp[i]` to be the maximum of its current value and `dp[j] + 1`, where `j` is the index of the smaller element.
    - Keep track of the overall maximum LIS found so far.
*/

//Code

//Rec+Mem
class Solution {
public:
    int n;
    int RecMem(vector<int>& nums, int prev_idx, int curr_idx, 
        vector<vector<int>> &dp) {

       if(curr_idx == n)
           return 0;
        
        if(prev_idx != -1 && dp[prev_idx][curr_idx] != -1)
            return dp[prev_idx][curr_idx];
        
        int pick = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
            pick = 1 + RecMem(nums, curr_idx, curr_idx+1, dp);
        
        int notPick = RecMem(nums, prev_idx, curr_idx+1, dp);
        
        if(prev_idx != -1)
            dp[prev_idx][curr_idx] =  max(pick, notPick);
        
        return max(pick, notPick);      
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return RecMem(nums, -1, 0, dp);
    }
};


//Tabulation

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        vector<int> dp(n, 1);
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }
        
        return maxLength;
    }
};


/*
Time and Space Complexity:

Approach-> Recursive (without Memoization) | Time Complexity-> O(2^N) (exponential) | Space Complexity-> O(N)
Approach-> Recursive (with Memoization)    | Time Complexity-> O(N^2)               | Space Complexity-> O(N^2)
Approach-> Tabulation (Bottom-Up)          | Time Complexity-> O(N^2)               | Space Complexity-> O(N)
*/
