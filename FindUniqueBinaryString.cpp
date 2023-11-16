/*
Problem Link: https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2023-11-16
*/

/*
Intuition:

The idea is to iterate through each binary string in the given array nums and toggle the bit at the same position.
This ensures that the resulting binary string will be different from each string in the array.
*/


/*
Algorithm:

1. Initialize an empty string `result` to store the final binary string.

2. Iterate through each position `i` in the binary strings.

3. For each position `i`, toggle the bit (change '0' to '1' and vice versa) at that position in the binary string.

4. Append the toggled bit to the `result` string.

5. Return the resulting binary string.

*/


/*
Learning from the problem :

This solution leverages the fact that the binary string at each position should be different from the original strings.
By toggling the bit at the same position in each string, we ensure that the resulting binary string is not present in the input array.

*/


/******************************************************************************************************/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result;

        //Iterate through each position in the binary strings
        for(int i=0; i<n; i++) {
            //Toggle the bit at the current position
            char ch = nums[i][i];

            //Append the opposite of toggled bit to the result string
            result += (ch == '0') ? "1" : "0";
        }
        
        //Return the resulting binary string
        return result;
    }
};

/******************************************************************************************************/

/*
Complexity
Time complexity: 
The time complexity of this solution is O(n), where n is the length of the input array nums.
This is because we iterate through each position in the binary strings once.

Space Complexity:
The space complexity is O(1) since the additional space used (the result string) is constant and does not depend on the input size.
*/