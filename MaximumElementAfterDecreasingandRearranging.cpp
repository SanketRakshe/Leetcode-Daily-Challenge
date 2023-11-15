/*
Problem Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/?envType=daily-question&envId=2023-11-15
*/

/*
Intuition:

The goal is to arrange the array in a way that satisfies the given conditions and maximizes the value of the largest element.
To achieve this, the algorithm sorts the array and then iterates through it to make necessary adjustments to meet the conditions.
*/

/*
Algorithm:

1. Sort the array: The first step is to sort the array in ascending order.
   This is a crucial step because it allows us to easily identify the elements that need adjustment.

2. Iterate through the sorted array: For each element in the sorted array, the algorithm performs the following steps:
   - If it's the first element (index 0), set it to 1.
   - If the absolute difference between the current element and the previous element is greater than 1, update the current element to be one more than the previous element. This ensures that the absolute difference between adjacent elements remains less than or equal to 1.

3. Track the maximum element: Keep track of the maximum element encountered during the iteration.

4. Return the maximum element: After the iteration, return the maximum element as it represents the maximum possible value of an element in the rearranged array.

*/


/*
Learning from the problem :

- Sorting the array simplifies the process of ensuring that adjacent elements have an absolute difference of at most 1. The algorithm
  focuses on adjusting elements only when necessary, which helps in achieving the maximum possible value for the largest element.

*/


/******************************************************************************************************/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        //Step 1: Sort the array in ascending order
        sort(begin(arr), end(arr));

        int n = arr.size();
        int maxElement = 1;

        //Step 2: Iterate through the sorted array
        for(int i = 0; i < n; i++) {
            //If it's the first element, set it to 1
            if(i == 0) {
                arr[i] = 1;
            } else if(arr[i] - arr[i-1] > 1) {
                //If the absolute difference is greater than 1, update the current element
                //to be one more than the previous element
                arr[i] = arr[i-1] + 1;
            }
            //Update the maximum element encountered during the iteration
            maxElement = max(maxElement, arr[i]);
        }
        //Step 4: Return the maximum element
        return maxElement;
    }
};

/******************************************************************************************************/

/*
Complexity
Time complexity: 
The time complexity is dominated by the sorting step, which is O(n log n), where n is the length of the array.
The subsequent iteration through the sorted array takes linear time, so the overall time complexity is O(n log n).

Space Complexity:
space complexity is O(1) since the algorithm uses a constant amount of extra space for variables like n, maxElement, and the loop index.
The sorting is performed in-place, so it doesn't contribute to additional space complexity.
*/