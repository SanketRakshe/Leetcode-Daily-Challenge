/*
Problem Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01
*/

/*
Intuition:
Sorting the array helps in forming arrays with minimum differences between elements. By considering groups of three sorted elements,
we can easily check and form arrays with the required conditions.

*/


/*
Algorithm:

1. Sort the array `nums` to make it easier to form arrays with the required conditions.

2. Iterate through the sorted array, considering each group of three elements.

3. Check if the difference between the first and last element in the group is less than or equal to `k`.

4. If yes, add this group as an array to the result.

5. If at any point the condition is not satisfied, return an empty array since it's impossible to form arrays with the given conditions.

*/


/*
Learning from the problem :
The problem involves sorting and grouping elements, understanding the importance of the difference condition. It emphasizes the importance
of breaking down the problem into smaller, manageable steps.
*/


/******************************************************************************************************/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<=n-3; i+=3) {
            if(nums[i+2] - nums[i] > k) {
                return {};
            }

            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
- Sorting the array takes O(n log n) time.
- The iteration through the sorted array is O(n).
- Thus, the overall time complexity is O(n log n).

Space Complexity:
- The space used is primarily for the result array.
- The space complexity is O(n/3), which simplifies to O(n).
*/