/*
Intuition:

- The core idea is to check if each distinct element in the array has a unique occurrence count.
- We need a way to efficiently track both the elements and their corresponding counts.

Thought Process:

1. Counting Occurrences: Use a hashmap (`unordered_map` in C++) to store element-count pairs. It provides fast key-based lookups for counting efficiently.
2. Tracking Unique Counts: Use a set (`unordered_set` in C++) to store the unique occurrence counts. Sets ensure uniqueness of elements.
3. Checking for Uniqueness: Compare the sizes of the hashmap and the set. If they're equal, it means each count is unique.

Algorithm:**

1. Create a hashmap `mp` and a set `s`.**
2. Iterate through the array `arr`:**
   - For each element `it`:
     - Increment its count in the hashmap: `mp[it]++`.
3. Iterate through the hashmap `mp`:**
   - For each element-count pair `it`:
     - Insert the count (value) into the set `s`.
4. Return `true` if the size of `mp` (number of unique elements) equals the size of `s` (number of unique counts), otherwise return `false`.**
*/

//code :

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        
        for(auto it: arr) {
            mp[it]++;
        }

        for(auto it: mp) {
            s.insert(it.second);
        }

        return mp.size() == s.size();
    }
};


/*
Time and Space Complexity:

- Time Complexity: O(n), where n is the length of the array.
   - Both hashmap and set operations are typically O(1) on average, leading to linear time complexity overall.
- Space Complexity: O(n), as the hashmap and set might store up to n distinct elements and counts in the worst case.
*/
