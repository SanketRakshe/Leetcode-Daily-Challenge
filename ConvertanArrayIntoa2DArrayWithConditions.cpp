/*

Problem Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

Intuition and Thought Process:
The goal is to create a 2D array from the given array `nums` with the following conditions:

1. The 2D array should contain only elements from `nums`.
2. Each row in the 2D array should contain distinct integers.
3. The number of rows in the 2D array should be minimal.

To achieve this, the algorithm maintains a mapping (`mp`) that keeps track of the frequency of each element encountered in `nums`.
The algorithm iterates through each element in `nums` and assigns it to a row in the 2D array based on its frequency.
If the frequency matches the current number of rows, a new row is added to the 2D array.


Algorithm:
1. Initialize an empty vector `result` to store the 2D array and a vector `mp` to keep track of the frequency of each element in `nums`.

2. Iterate through each element in `nums`.
   - Get the frequency of the current element from `mp`.
   - If the frequency equals the current number of rows in `result`, add a new empty row to `result`.
   - Append the current element to the row corresponding to its frequency.
   - Update the frequency in `mp`.

3. Return the resulting 2D array.

Learning:
The algorithm utilizes the fact that distinct elements should be placed in different rows,
and by keeping track of the frequency, it ensures that each element is placed in the correct row.


Code:
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // Get the length of the input array
        int n = nums.size();

        // Mapping to store the frequency of each element
        vector<int> mp(n + 1);

        // Resulting 2D array
        vector<vector<int>> result;

        // Iterate through each element in the input array
        for (int &num : nums) {
            // Get the frequency of the current element
            int freq = mp[num];

            // If the frequency equals the current number of rows, add a new row
            if (freq == result.size()) {
                result.push_back({});
            }

            // Append the current element to the row corresponding to its frequency
            result[freq].push_back(num);

            // Update the frequency in the mapping
            mp[num]++;
        }

        // Return the resulting 2D array
        return result;
    }
};



/*
- **Time Complexity: The algorithm iterates through each element in `nums` once, and for each element, it performs constant time operations (insertion and update in vectors).
                     Therefore, the time complexity is O(N), where N is the length of `nums`.

- **Space Complexity: The additional space used by the algorithm is proportional to the number of distinct elements in `nums` and the number of rows in the resulting 2D array.
                      In the worst case, where all elements are distinct, the space complexity is O(N).

*/

