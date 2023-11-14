/*
Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2023-11-14
*/

/*
Intuition:

The algorithm identifies first and last occurrences of each character to find potential substrings in a given string.
It iterates through the string, using an unordered set to count unique characters within valid substrings.
This count represents the unique palindromic subsequences of length three that can be formed with each character.
The process is repeated for all characters in the alphabet, accumulating counts and yielding the total number of such palindromic subsequences in the string.
This approach optimally explores the string, ensuring a concise and effective solution.
*/

/*
Algorithm:

1. Initialize a vector `indices` to store the first and last occurrence indices of each character in the string.

2. Iterate through the string and populate the `indices` vector.

3. For each character with valid occurrences, iterate through the string between its first and last occurrence indices, and count the unique characters.

4. Add the count to the result.

5. Repeat for all characters in the alphabet.

6. Return the final result.

*/


/*
Learning from the problem :

- The code utilizes the concept of first and last occurrence indices to efficiently find the valid substrings for each character.
  It uses an unordered set to keep track of unique characters within a substring, ensuring each subsequence is counted only once.

*/


/******************************************************************************************************/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        //Create a vector to store the first and last occurrence indices of each character in the string
        vector<pair<int, int>> indices(26, {-1, -1});
        
        //Populate the indices vector with the first and last occurrence indices of each character
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = ch - 'a';
            
            if (indices[idx].first == -1) {
                indices[idx].first = i;
            }
            
            indices[idx].second = i;
        }
        
        int result = 0;
        
        //Iterate through each character's occurrence indices
        for(int i = 0; i < 26; i++) {
            //If the character doesn't occur in the string, skip it
            if(indices[i] == make_pair(-1, -1)) {
                continue;
            }
            
            //Use an unordered set to store unique characters between the first and last occurrence indices
            unordered_set<char> st;
            
            //Iterate through the string between the first and last occurrence indices of the character
            for(int middle = indices[i].first + 1; middle <= indices[i].second - 1; middle++) {
                // Insert each character into the set
                st.insert(s[middle]);
            }
            
            //Add the size of the set to the result, representing the number of unique characters between occurrences
            result += st.size();
        } 
        return result;
    }
};

/******************************************************************************************************/

/*
Complexity
Time complexity: 
- The time complexity is O(n), where n is the length of the input string.
  This is because we iterate through the string once and perform constant time operations in each iteration.

Space Complexity:
- The space complexity is O(1) because the size of the `indices` vector and the unordered set (`st`) are both constant, independent of the input size.
*/