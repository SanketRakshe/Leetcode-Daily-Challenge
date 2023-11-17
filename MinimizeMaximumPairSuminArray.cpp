/*
Problem Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2023-11-17
*/

/*
Intuition:

The algorithm aims to minimize the maximum pair sum by sorting the array and pairing up its elements with a two-pointer approach.
This ensures that the largest and smallest elements are paired together, effectively minimizing the overall maximum pair sum.
*/


/*
Algorithm:

1. Sort the input array in ascending order.

2. Initialize two pointers, one at the beginning and one at the end of the sorted array.

3. Pair up elements by moving the pointers towards each other, calculating the sum of each pair.

4. Update the maximum pair sum if the current sum is greater.

5. Return the minimized maximum pair sum.

*/


/*
Learning from the problem :

sorting the array is a smart move to efficiently pair up elements.
Using two pointers helps find pairs that minimize the maximum sum,
highlighting the value of thoughtful algorithm design and working with sorted data.

*/


/******************************************************************************************************/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Sorting the array to pair up the elements for minimized maximum pair sum
        sort(begin(nums), end(nums));

        int maxResult = 0;

        // Initializing two pointers, i at the beginning and j at the end of the sorted array
        int i = 0, j = nums.size() - 1;

        // Pairing up elements to minimize the maximum pair sum
        while (i < j) {
            int sum = nums[i] + nums[j];

            // Update the maximum pair sum if the current sum is greater
            maxResult = max(maxResult, sum);

            // Move the pointers towards each other
            i++;
            j--;
        }
        // Return the minimized maximum pair sum
        return maxResult;
    }
};

/******************************************************************************************************/

/*
Complexity
Time complexity: 
The time complexity is dominated by the sorting step, which is O(n log n), where n is the size of the input array.

Space Complexity:
The space complexity is O(1) as the algorithm uses a constant amount of extra space. Sorting is typically done in-place,
and the only additional space used is for variables like pointers and the maxResult variable.
*/