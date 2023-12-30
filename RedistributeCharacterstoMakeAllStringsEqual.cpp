/*
Problem Link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/?envType=daily-question&envId=2023-12-30
*/

/*

Intuition:
Focus on character frequencies:** The key insight is that the specific arrangement of characters within each string doesn't matter.
What matters is the overall frequency of each character across all strings.

Equal distribution:** If we can distribute each character evenly among all strings,
we can rearrange those characters within each string to make them equal.

*/

/*

Algorithm:

1. Initialize a count array:** Create an array `count` of size 26 to store the frequency of each character (a to z).

2. Iterate through each string and character:
   - For each string in the input array, iterate through its characters.
   - Increment the corresponding count in the `count` array.

3. Check for even divisibility:
   - Iterate through the `count` array.
   - For each character, check if its count is divisible by the number of strings.
   - If not, return false.

4. If all characters pass the test, return true.

*/

/*

Learning from the problem :

- Character frequencies: This problem highlights the importance of analyzing character frequencies in string problems.
- Even distribution: Recognizing the condition for even distribution is crucial for solving this problem efficiently.
- Divisibility trick: The divisibility check is a clever way to quickly determine if equal distribution is possible.
- Focus on key constraints: Notice that the specific order of characters within strings is irrelevant, leading to a simpler solution.

*/




/******************************************************************************************************/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //Get the total number of words
        int n = words.size();

        //Array to store the count of each character
        int count[26] = {0};

        //Iterate through each word and each character, updating the count array
        for(string &word: words) {
            for(char &ch: word) {
                count[ch - 'a']++;
            }
        }

        //Check if each character count is divisible by the total number of words
        for(int i=0; i<26; i++) {
            if(count[i] % n != 0) {
                //If not divisible, return false
                return false;
            }
        }

        //If all character counts are divisible, return true
        return true;
    }
};


/******************************************************************************************************/

/*

Complexity

Time Complexity: O(n), where n is the total number of characters in all strings. This is because we iterate through each character once to count frequencies.

Space Complexity: O(1), assuming a fixed alphabet size (26 lowercase letters). The `count` array has a constant size regardless of the input size.

*/