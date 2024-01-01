/*

Problem Link: https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01

Intuition and Thought Process:
The goal is to maximize the number of content children, where each child has a greed factor (minimum cookie size they are content with),
and there are cookies with various sizes. The key insight here is to distribute the cookies starting from the child with the smallest greed factor. By doing this,
you ensure that you use the smallest cookies for the children with the least demanding preferences.

Algorithm:
1. Sort the greed factors array (`g`) in ascending order.
2. Sort the cookie sizes array (`s`) in ascending order.
3. Initialize two pointers, `i` for the greed factors array and `j` for the cookie sizes array, both starting from 0.
4. Iterate through the arrays using the pointers:
   - If `g[i]` (greed factor of the current child) is less than or equal to `s[j]` (size of the current cookie),
     it means this child can be satisfied. Move to the next child (`i++`).
   - Move to the next cookie (`j++`) in any case.
5. Continue this process until either all children are satisfied or you run out of cookies.

Learning:
The idea of sorting both arrays and using two pointers to iterate through them is a common strategy for optimization problems.
In this case, sorting helps in efficiently matching the smallest available cookies to the children with the least demanding preferences.


Code:
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Get the size of the arrays
        int n = g.size();
        int m = s.size();

        // Sort the arrays in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Initialize pointers for greed factors (i) and cookie sizes (j)
        int i = 0, j = 0;

        // Iterate through the arrays
        while (i < n && j < m) {
            // If the current cookie can satisfy the current child's greed factor
            if (g[i] <= s[j]) {
                // Move to the next child
                i++;
            }
            // Move to the next cookie in any case
            j++;
        }

        // The value of i represents the number of content children
        return i;
    }
};



/*
Time Complexity:
The time complexity is dominated by the sorting step, which is O(n log n) for both arrays. The subsequent iteration through the arrays is linear,
O(n). Hence, the overall time complexity is O(n log n).

Space Complexity:
The space complexity is O(1) since the algorithm uses only a constant amount of extra space (for the pointers and some temporary variables),
regardless of the input size. Sorting is an in-place operation and doesn't require additional space proportional to the input size.

*/

