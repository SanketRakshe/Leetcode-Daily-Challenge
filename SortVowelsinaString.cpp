/*
Problem Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2023-11-13
*/

/*
Intuition:

The problem requires rearranging a given string s such that the consonants remain in their original positions,
and the vowels are sorted in non-decreasing order based on their ASCII values. The goal is to achieve this rearrangement efficiently.
*/

/*
Algorithm:

1. Create a helper function `isVowel` to check if a given character is a vowel. It converts the character to lowercase for case-insensitivity.

2. Initialize an unordered map `mp` to store the count of each vowel in the input string `s`.

3. Create a string `temp` containing all vowels in both uppercase and lowercase.

4. Iterate through the string `s`. If the current character is a vowel, update it with the next vowel from the sorted `temp` string. 
   Decrease the count of that vowel in the map `mp`.

5. Return the modified string `s`.

*/


/*
Learning from the problem :

1. The problem involves sorting a subset of characters in a string while keeping another subset in their original order.
   It teaches us to manipulate strings based on specific conditions.

2. The solution uses a map to keep track of the count of each vowel, allowing for efficient retrieval and updating of vowel characters in the string.

*/




/******************************************************************************************************/

class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch); // Convert the character to lowercase for case-insensitivity

        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> mp; // Map to store the count of each vowel

        // Count the occurrences of each vowel in the input string
        for(auto &ch: s) {
            if(isVowel(ch)) {
                mp[ch]++;
            }
        }

        string temp = "AEIOUaeiou"; // String containing all vowels in both uppercase and lowercase

        int j = 0; // Pointer for the temp string (current vowel)

        // Iterate through the input string
        for(int i=0; i<s.length(); i++) {
            if(isVowel(s[i])) { // If the current character is a vowel
                while(mp[temp[j]] == 0) {
                    j++; // Find the next available vowel in the sorted order
                }

                s[i] = temp[j]; // Update the vowel in the string
                mp[temp[j]]--; // Decrease the count of that vowel in the map
            }
        }
        return s; // Return the modified string
    }
};

/******************************************************************************************************/

/*
Complexity
Time complexity: 
???

Space Complexity:
???
*/