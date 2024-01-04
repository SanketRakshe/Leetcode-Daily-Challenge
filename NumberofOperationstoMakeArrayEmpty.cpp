/*

Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04

Problem Intuition:
The problem involves finding the minimum number of operations required to make an array empty.
The operations involve removing either two or three elements with equal values from the array.
The goal is to find an optimal way to perform these operations.

Thought Process:
1. Count Frequency:
   - Create a hash map (`hsh`) to store the frequency of each unique element in the array.

2. Iterate Through Elements:
   - Iterate through the unique elements in the hash map.
   - For each element's frequency, try to perform operations to reduce the count to zero.

3. Operations:
   - Use as many pairs of operations (deleting two equal elements) as possible.
   - If there are remaining elements, use the triplets of operations (deleting three equal elements).

4. Check Possibility:
   - If at any point, a single element is left and cannot form a pair or triplet, return -1 as it's not possible to empty the array.


Algorithm:

1. Initialize a hash map (`hsh`) to store the frequency of each element in the array.

2. Iterate through the array and populate the hash map.

3. Initialize a variable `ans` to track the number of operations.

4. Iterate through the hash map:
   - For each element's frequency, try to use pairs and triplets of operations to reduce the count to zero.
   - If a single element is left, return -1.

5. Return the total number of operations (`ans`).


Learning:

- The key insight is to recognize that using pairs of operations is more efficient than using triplets.
- The solution follows a greedy approach by using pairs and triplets optimally.

Code:
*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Step 1: Count the frequency of each element in the array
        unordered_map<int, int> hsh;
        for (int num : nums) {
            hsh[num]++;
        }
        
        // Step 2: Initialize the variable to track the number of operations
        int ans = 0;

        // Step 3: Iterate through the unique elements in the hash map
        for (const auto& entry : hsh) {
            int val = entry.second;
            
            // Step 4: Try to use pairs and triplets of operations to reduce the count to zero
            while (val) {
                // If there's only one element left, it's not possible to empty the array
                if (val == 1) {
                    return -1;
                }

                // If there are four or two elements, use pairs of operations
                if (val == 4 || val == 2) {
                    val -= 2;
                    ans++;
                } 
                // If there are three elements, use triplets of operations
                else {
                    val -= 3;
                    ans++;
                }
            }
        }
        
        // Step 5: Return the total number of operations
        return ans;
    }
};



/*
Time Complexity:
- The time complexity is O(N), where N is the length of the input array.
This is because we iterate through the array to populate the hash map.

Space Complexity:
- The space complexity is O(U), where U is the number of unique elements in the array.
This is because we use a hash map to store the frequency of each unique element. In the worst case, all elements are unique, leading to O(N) space complexity.
*/

