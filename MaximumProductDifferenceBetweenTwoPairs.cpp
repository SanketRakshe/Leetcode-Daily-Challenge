/*
Problem Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/?envType=daily-question&envId=2023-12-18


Intuition and Thought Process:

1. Observation:
   - To maximize the product difference between two pairs, it's beneficial to have a large product for one pair and a small product for the other.
   - Sorting the array helps to identify the largest and second-largest values, as well as the smallest and second-smallest values.

2. Approach:
   - Initialize four variables: `largest`, `secondLargest`, `smallest`, and `secondSmallest`.
   - Iterate through the array, updating these variables to keep track of the largest, second-largest, smallest, and second-smallest values.


Algorithm:
   - For each element in the array:
     - Update `largest` and `secondLargest` based on the current element.
     - Update `smallest` and `secondSmallest` based on the current element.
   - Calculate the product difference using the identified values.


Example:
   - For the input [5, 6, 2, 7, 4]:
     - Largest: 7, Second Largest: 6
     - Smallest: 2, Second Smallest: 4
     - Product Difference: (7 * 6) - (2 * 4) = 42 - 8 = 34


Learning from the problem :

1. Sorting vs. Iterating:
   - Instead of sorting the entire array, this solution optimizes by iterating through the array once, reducing the time complexity.

2. Maintaining State:
   - The approach relies on maintaining the state of the largest, second-largest, smallest,
     and second-smallest values during the iteration to optimize the calculation of the product difference.

3. Trade-offs:
   - The solution emphasizes a trade-off between simplicity and performance,
     choosing to sacrifice a bit of clarity for efficiency by avoiding sorting.





/******************************************************************************************************/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // Initialize variables to keep track of the largest and second-largest values
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        // Initialize variables to keep track of the smallest and second-smallest values
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        // Iterate through the array
        for (int &num : nums) {
            // Update largest and secondLargest based on the current element
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else {
                secondLargest = std::max(secondLargest, num);
            }

            // Update smallest and secondSmallest based on the current element
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = std::min(secondSmallest, num);
            }
        }

        // Calculate the product difference using the identified values
        return (largest * secondLargest) - (secondSmallest * smallest);
    }
};


/******************************************************************************************************/

/*

Complexity
Time Complexity: O(n) due to two linear passes through the array.

Space Complexity: O(1) as we only use constant extra space for storing the candidate values.

*/