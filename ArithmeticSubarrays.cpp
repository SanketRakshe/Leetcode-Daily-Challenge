/*
Problem Link: https://leetcode.com/problems/arithmetic-subarrays/description/?envType=daily-question&envId=2023-11-23
*/

/*
Intuition:
The intuition behind solving this problem is to check if any permutation of the given subarray can form an arithmetic sequence.
If it is possible for at least one permutation, then the answer for that query is true; otherwise, it's false.
*/


/*
Algorithm:

1. check Function:
   - This function takes a subarray `arr` and checks if it can be rearranged to form an arithmetic sequence.
   - It does this by sorting the subarray and then checking if the differences between consecutive elements are the same.
   - If the differences are consistent, the function returns true; otherwise, it returns false.

2. checkArithmeticSubarrays Function:
   - This function iterates through the given range queries (`l` and `r`).
   - For each query, it extracts the corresponding subarray from the `nums` array.
   - It then calls the `check` function on the subarray and appends the result to the `result` vector.

*/


/*
Learning from the problem :
- The problem introduces the concept of checking whether a subarray can be rearranged to form a specific pattern (arithmetic sequence).
- Sorting the subarray simplifies the process of checking for a consistent difference between consecutive elements.
- The solution uses a modular structure, with a separate function for the core logic (`check`) and another for handling the range queries.
*/


/******************************************************************************************************/

class Solution {
public:
    bool check(vector<int> &arr) {
        sort(begin(arr), end(arr));
        int n = arr.size();
        
        int d = arr[1] - arr[0];
        
        for(int i = 2; i<n; i++) {
            if(arr[i] - arr[i-1] != d) {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r){
        int m = l.size();
        vector<bool> result;
        for(int i = 0; i<m; i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            result.push_back(check(arr));   
        }
        return result;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
- The time complexity of the `check` function is O(k * log(k)), where k is the size of the subarray. This is because of the sorting operation.
- The `checkArithmeticSubarrays` function iterates through all the queries, so its time complexity is O(m * k * log(k)), where m is the number of queries.

Space Complexity:
- The space complexity is primarily determined by the sorting operation in the `check` function. Sorting a subarray requires O(k) additional space.
- The space complexity of the entire solution is O(m * k), where m is the number of queries and k is the size of the largest subarray.
*/