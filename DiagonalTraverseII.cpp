/*
Problem Link: https://leetcode.com/problems/diagonal-traverse-ii/?envType=daily-question&envId=2023-11-22
*/

/*
Intuition:
The problem requires traversing a 2D array in diagonal order.
To achieve this, we can observe that elements with the same diagonal index (sum of row and column indices) belong to the same diagonal.
We need to process diagonals from bottom to top and left to right.

*/


/*
Algorithm:

1. Initialize an unordered_map `mp` to store elements based on their diagonal index.

2. Traverse the input `nums` matrix from bottom to top and left to right.
   - For each element `nums[row][col]`, calculate its diagonal index as `row + col` and add the element to the corresponding diagonal in the map.

3. Initialize an empty vector `result` to store the final result.

4. Initialize a variable `diagonal` to 0.

5. Iterate through the map until there are no more diagonals to process (`mp.find(diagonal) != mp.end()`).
   - For each diagonal, append the elements in reverse order (bottom to top) to the result vector.
   - Increment the diagonal index.

6. Return the final result vector.

*/


/*
Learning from the problem :
To think creatively about how to traverse a matrix in a specific order, in this case, diagonally. Utilizing a map to group elements based on their diagonal index helps in simplifying the traversal process.

*/


/******************************************************************************************************/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        
        for(int row = nums.size()-1; row >= 0; row--) {
            for(int col = 0; col < nums[row].size(); col++) {
                mp[row+col].push_back(nums[row][col]);
            }
        }
        
        vector<int> result;
        int diagonal = 0;
        
        while(mp.find(diagonal) != mp.end()) {
            
            for(int &num : mp[diagonal]) {
                result.push_back(num);
            }
            diagonal++;
        }
        return result;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
The time complexity is O(N * M), where N is the total number of rows and M is the maximum number of columns in any row.
This is because, in the worst case, we might have to iterate through all the elements in the matrix.
The outer loop runs in O(N) time, and the inner loop runs in O(M) time.

Space Complexity:
The space complexity is O(N * M) as well. In the worst case, each element in the matrix may end up in the map,
and there can be a total of N * M elements in the map..
*/