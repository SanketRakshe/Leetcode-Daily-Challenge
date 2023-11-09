/*
Problem Link: https://leetcode.com/problems/count-number-of-homogenous-substrings/description/?envType=daily-question&envId=2023-11-09
*/

/*

Intuition & Algorithm:
The algorithm to solve this problem is relatively simple. I iterated through the input string s,
keeping track of the current homogeneous substring's length. Whenever I encounter a character that is the same as the previous character,
I incremented the length of the current homogeneous substring.
When I encounter a character that is different from the previous one, I reset the length to 1 (as the new character starts a new homogeneous substring),
and added the length of the current substring to the result.

The key insight here is that you don't need to generate and store all the substrings explicitly.
Instead, you can count them as you traverse the input string.

*/

/*

Learning from the problem :

From this problem, I learned the significance of optimizing string processing to enhance efficiency.
By counting homogeneous substrings iteratively, I successfully reduced both time and space complexity to O(n) and O(1), respectively.
This experience underscored the importance of recognizing patterns within data,
highlighting the significance of algorithmic optimization for more efficient problem-solving in algorithmic and data-driven applications.

*/




/******************************************************************************************************/

class Solution {
public:
    int MOD = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.length();
        int result = 0;
        int length = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                // If the current character is the same as the previous one,
                // increment the length of the current homogeneous substring.
                length++;
            } else {
                // If the current character is different from the previous one,
                // reset the length to 1 (start a new homogeneous substring).
                length = 1;
            }
            // Add the length of the current homogeneous substring to the result.
            result = (result + length) % MOD;
        }
        return result;
    }
};


/******************************************************************************************************/

/*

Complexity
Time complexity: 
 O(n), where n is the length of the input string s. We iterate through the string once.


Space Complexity:
O(1), as we only use a constant amount of extra space for variables.

*/