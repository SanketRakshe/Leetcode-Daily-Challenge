/*
Problem Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
*/

/*
Intuition:
The goal of this problem is to maximize the frequency of an element in the given array by performing at most k operations.
To achieve this, we can sort the array and use a sliding window approach to efficiently find the maximum frequency.

*/


/*
Algorithm:

1. Sort the given array `nums` in non-decreasing order.

2. Initialize variables: `maxFreq` to track the maximum frequency, `total` to store the sum of elements within
   the current window, and `l` and `r` as pointers for the sliding window.

3. Iterate over the array using the right pointer `r`:
   a. Add the current element to the `total`.
   b. Check if it's possible to reduce the window size by incrementing the left pointer `l` while maintaining the sum within the limits (total + k). If yes, increment `l` and subtract the corresponding element from `total`.
   c. Update `maxFreq` with the maximum frequency encountered so far (length of the current window).

4. Return the final `maxFreq`.

*/


/*
Learning from the problem :

Sorting the array is a key step to simplify the process of finding the maximum frequency efficiently.
The sliding window technique helps in maintaining a valid subarray while optimizing the operations.
Careful consideration of conditions and bounds is crucial for optimizing the solution.

*/


/******************************************************************************************************/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Step 1: Sort the array in non-decreasing order
        std::sort(nums.begin(), nums.end());

        // Initialize variables
        long long int maxFreq = 1;  // to track maximum frequency
        long long int total = 0;    // to store the sum of elements within the current window
        long long int l = 0, r = 0;  // pointers for the sliding window
        long long int n = nums.size();

        // Step 2: Iterate over the array using the right pointer 'r'
        for (r = 0; r < n; r++) {
            // Step 3a: Add the current element to 'total'
            total += nums[r];

            // Step 3b: Check if it's possible to reduce the window size by incrementing 'l'
            // while maintaining the sum within the limits (total + k)
            if ((l + 1 <= r) && (nums[r] * (r - l + 1) > total + k)) {
                // Increment 'l' and subtract the corresponding element from 'total'
                total -= nums[l];
                l++;
            }

            // Step 3c: Update 'maxFreq' with the maximum frequency encountered so far
            maxFreq = std::max(maxFreq, r - l + 1);
        }

        // Step 4: Return the final 'maxFreq'
        return maxFreq;
    }
};

/******************************************************************************************************/

/*
Complexity
Time complexity: 
The time complexity is dominated by the sorting step, which is O(n log n), where n is the size of the input array.
The sliding window iteration is linear, so the overall time complexity is O(n log n).

Space Complexity:
The space complexity is O(1) as the algorithm uses only a constant amount of extra space.
*/