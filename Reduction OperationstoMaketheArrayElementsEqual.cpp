/*
Problem Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/?envType=daily-question&envId=2023-11-19
*/

/*
Intuition:
The goal is to make all elements in the array equal through a series of operations.
The key insight here is to recognize that reducing an element to the next smaller distinct value is a step towards making all elements equal.
The order in which we choose the elements to reduce affects the number of operations required.

*/


/*
Algorithm:

1. Sort the array in non-decreasing order.

2. Iterate through the sorted array from the end (largest values) to the beginning.

3. For each element, if it is the same as the previous element, skip to the next iteration.

4. Otherwise, update the operations count by adding the difference between the current index and the total number of elements.
   This reflects the number of operations needed to reduce the current element to the smallest distinct value.

5. Continue this process until the beginning of the array is reached.

*/


/*
Learning from the problem :
Sorting can significantly improve algorithm efficiency. Greedy algorithms make locally optimal choices to achieve an overall optimal solution.
Sorting algorithms typically have logarithmic space complexity.


*/


/******************************************************************************************************/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        // Get the size of the input array
        int n = nums.size();
        // Initialize the count of operations
        int ops = 0;

        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());

        // Iterate through the sorted array from the end
        for(int i = n - 1; i > 0; i--) {
            // If the current element is equal to the previous element, skip to the next iteration
            if(nums[i] == nums[i - 1]) 
                continue;

            // Update the operations count by adding the difference between the current index and the total number of elements
            ops += (n - i);
        }

        // Return the total number of operations
        return ops;
    }
};


/******************************************************************************************************/

/*
Complexity
Time complexity: 
The time complexity is dominated by the sorting step, which is O(n log n) due to the use of the standard sorting algorithm.
The subsequent iteration through the sorted array is O(n). Therefore, the overall time complexity is O(n log n).

Space Complexity:
The space complexity is O(log n), assuming in-place sorting.
*/