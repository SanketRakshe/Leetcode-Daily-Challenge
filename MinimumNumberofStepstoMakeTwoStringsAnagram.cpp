/*
Problem Intuition:
The problem asks for the minimum number of steps needed to make two strings, `s` and `t`, anagrams of each other.
An anagram is a word or phrase formed by rearranging the letters of another. In this context,
it means that the two strings should have the same characters with a possibly different order.

### Thought Process:
To solve this problem, the idea is to compare the frequency of each character in both strings. 
We need to identify the characters that are in excess in one string compared to the other and calculate the minimum steps required 
to make the frequency distribution equal.

Algorithm:
1. Initialize two arrays `s_map` and `t_map` of size 26 (assuming lowercase English letters) to store the frequency of each character 
   in both strings.
2. Traverse both strings simultaneously and update the frequency arrays.
3. Iterate through the arrays and for each character, calculate the difference in frequencies between `s` and `t`.
   If `t` has fewer occurrences of a character, add the difference to the result.
4. The result represents the minimum number of steps needed to make `t` an anagram of `s`.

### Learning:
This algorithm leverages the concept of frequency distribution to identify the characters that need to be replaced to make two strings anagrams.
The use of frequency arrays simplifies the comparison and calculation process.
*/

//Code:

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();

        int s_map[26] = {0};
        int t_map[26] = {0};

        for (int i = 0; i < n; i++) {
            s_map[s[i] - 'a']++;
            t_map[t[i] - 'a']++;
        }

        int res = 0;

        for (int i = 0; i < 26; i++) {
            int freqT = t_map[i];
            int freqS = s_map[i];

            if (freqT < freqS) {
                res += freqS - freqT;
            }
        }
        return res;
    }
};

/*
### Time Complexity:
The time complexity is O(n), where n is the length of the strings.
The algorithm traverses both strings once and performs constant-time operations for each character.

### Space Complexity:
The space complexity is O(1) because the size of the frequency arrays is constant (26) and does not depend on the length of the strings.
Therefore, it's considered constant space, which is efficient.
*/