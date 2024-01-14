/*
Intuition:

- The key insight is that the allowed operations don't change the overall frequency of characters in a string, but only their arrangement.
- Two strings can only be close if they have the exact same character frequencies and the same set of unique characters.

Thought Process:

1. Check for character mismatches:** If any character appears in one string but not the other, they cannot be close.
2. Check for frequency mismatches:** If the frequencies of characters (ignoring their order) dont match, they cannot be close.
3. Sort and compare frequencies:** To ensure the frequencies match, sort the frequency arrays and compare them element-wise.

Algorithm:

1. Create frequency arrays: Use two arrays to store the frequency of each character (a-z) in both strings.
2. Check for character mismatches: Iterate through both arrays and return false if any character has a non-zero frequency
   in one array but zero in the other.
3. Sort frequency arrays: Sort both frequency arrays to align character frequencies for comparison.
4. Compare sorted frequencies: Iterate through the sorted arrays and return false if any corresponding elements are different.
5. Return true: If all checks pass, the strings are close.

Learnings:

Focus on invariants: Identify properties that remain unchanged by allowed operations to simplify problem-solving.
Reduce complexity: Analyzing character frequencies simplifies string comparisons.
Think about sorting: Sorting can be helpful for comparing distributions of values.
*/

//Code:

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) ||
            (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
};




/*
Time and Space Complexity:

Time Complexity: O(n log n) due to character counting and sorting.
Space Complexity: O(1) or constant, as the frequency arrays have a fixed size of 26, regardless of input string lengths.
*/