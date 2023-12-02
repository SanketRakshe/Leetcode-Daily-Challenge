/*
Problem Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/?envType=daily-question&envId=2023-12-02
*/

/*
Intuition:
The problem requires counting the sum of lengths of strings that can be formed using characters from a given string `chars`.
The condition is that each character in `chars` can only be used once.
The code iterates through the words and checks if they can be formed from the characters in `chars`.
*/


/*
Algorithm:

1. Initialize a vector `charCount` of size 26 to store the count of each character in `chars`.

2. Iterate through each character in `chars` and update the count in `charCount`.

3. Initialize `result` to 0, which will be used to store the sum of lengths of good strings.

4. Iterate through each word in the `words` array.
    a. For each word, initialize a vector `wordCount` of size 26 to store the count of each character in the word.
    b. Iterate through each character in the word and update the count in `wordCount`.
    c. Check if the word can be formed using characters from `chars`. If yes, add the length of the word to the `result`.

5. Return the final result.

*/


/*
Learning from the problem :
This problem highlights the importance of character counting and comparison in string manipulation.
The solution involves efficiently tracking the frequency of characters in both the input string and individual words,
enabling a straightforward check for the possibility of forming each word from the given characters.
This approach underscores the significance of meticulous character-level analysis in solving related string manipulation problems.
*/


/******************************************************************************************************/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Step 1: Initialize a vector to store the count of each character in chars.
        vector<int> charCount(26, 0);

        // Step 2: Update the count of each character in chars.
        for(char &ch : chars) {
            charCount[ch - 'a']++;
        }

        // Step 3: Initialize the result variable to store the sum of lengths.
        int result = 0;

        // Step 4: Iterate through each word in words.
        for(string &word : words) {
            // Step 4a: Initialize a vector to store the count of each character in the word.
            vector<int> wordCount(26, 0);

            // Step 4b: Update the count of each character in the word.
            for(char &ch : word) {
                wordCount[ch - 'a']++;
            }

            // Step 4c: Check if the word can be formed using characters from chars.
            bool ok = true;
            for(int i = 0; i < 26; i++) {
                if(wordCount[i] > charCount[i]) {
                    // If a character in the word has a count greater than in chars, it's not possible.
                    ok = false;
                    break;
                }
            }

            // If the word can be formed, add its length to the result.
            if(ok) {
                result += word.size();
            }
        }

        // Step 5: Return the final result.
        return result;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
Let `n` be the total number of characters in all words and `m` be the length of the `chars` string.
- Constructing `charCount` takes O(m) time.
- Iterating through each word and constructing `wordCount` takes O(n) time.
- The overall time complexity is O(n + m).

Space Complexity:
- The space complexity is O(1) for the constant-size vector `charCount` (since it has a fixed size of 26).
- The space complexity is O(1) for the constant-size vector `wordCount` (since it also has a fixed size of 26).
- Therefore, the overall space complexity is O(1).
*/