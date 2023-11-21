/*
Problem Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/?envType=daily-question&envId=2023-11-21
*/

/*
Intuition:
The problem requires finding pairs of indices (i, j) such that certain conditions are satisfied. To simplify the problem,
the solution subtracts the reversed value of each element from itself and checks for equality between pairs.
The key observation is that if `nums[i] - reverse(nums[i]) == nums[j] - reverse(nums[j])`, then `(nums[i], nums[j])` is a nice pair.

*/


/*
Algorithm:

1. Reverse Function:
   - The `reverse` function is a utility function to reverse a non-negative integer. It uses a while loop to reverse the digits of the number.

2. Processing Array Elements:
   - Iterate through the given array `nums`.
   - For each element `nums[i]`, subtract the reverse of it, i.e., `nums[i] - reverse(nums[i])`. This simplifies the problem, and now we are looking for pairs where this difference is the same.

3. Counting Nice Pairs:
   - Initialize an unordered map `mp` to store the frequency of the differences.
   - For each processed element, update the result by adding the current frequency of the difference in `mp` to it. Also, increment the frequency in `mp`.
   - The result is updated in this way to count the number of nice pairs.

4. Modulo Operation:
   - Keep track of the result modulo 10^9 + 7 to handle large numbers and prevent overflow.

*/


/*
Learning from the problem :
This problem highlights the significance of transforming complex conditions into simpler forms for efficient problem-solving.
By subtracting the reversed value from each element, the problem is streamlined,
leading to a more straightforward comparison for identifying nice pairs. Additionally, the use of data structures,
such as the unordered map, showcases the importance of selecting appropriate tools to efficiently manage and process information,
contributing to an optimized and scalable solution.

*/


/******************************************************************************************************/

class Solution {
public:
  // Define a constant for modulo operation
  int M = 1e9+7;

  int reverse(int num) {
    int rev = 0;
    while(num > 0) {
      int rem = num % 10;
      rev = rev * 10 + rem;
      num /= 10;
    }
    return rev;
  }

  int countNicePairs(vector<int>& nums) {
    int n = nums.size();

    // Map to store frequencies of differences
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {
      // Subtract the reverse of the element from itself
      nums[i] = nums[i] - reverse(nums[i]);
    }

    int result = 0;

    // Iterate through the processed array
    for(int i = 0; i < n; i++) {
      // Update the result by adding the current frequency of the difference
      // to handle nice pairs
      result = (result + mp[nums[i]]) % M;
      // Increment the frequency in the map
      mp[nums[i]]++;
    }
    
    return result;
  }
};




/******************************************************************************************************/

/*
Complexity

Time complexity: 
The solution iterates through the array once, performing constant-time operations for each element.
Therefore, the time complexity is O(N), where N is the length of the array.

Space Complexity:
The space complexity is O(N) as the solution uses an unordered map to store frequencies,
and the size of the map is proportional to the number of elements in the array.
*/