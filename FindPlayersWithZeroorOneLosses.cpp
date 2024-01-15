/*
Intuition:

Efficiently track players' losses to identify those with zero or one loss. Use a data structure that quickly associates players with their loss counts.

Thought Process:

1. Count losses: Use a hash map to store player IDs as keys and their loss counts as values.
2. Identify players with zero losses:
   - If a player is a winner in a match but not yet in the hash map, they have no losses.
   - Add them to the `notLost` list and mark them in the hash map with a special value (e.g., 2) to avoid reprocessing.
3. Identify players with one loss:
   - If a player's loss count in the hash map reaches 1, add them to the `oneLost` list.
4. Sort and return results:** Sort both lists in ascending order to meet the output format.
*/

//Code:

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;

        for(auto it: matches) {
            int lose = it[1];
            lost[lose]++;
        }

        vector<int> notLost;
        vector<int> oneLost;

        for(auto it: matches) {
            int win  = it[0];
            int lose = it[1];

            if(lost[lose] == 1) {
                oneLost.push_back(lose);
            }

            if(lost.find(win) == lost.end()) {
                notLost.push_back(win);
                lost[win] = 2;
            }
        }

        sort(notLost.begin(), notLost.end());
        sort(oneLost.begin(), oneLost.end());

        return {notLost, oneLost};
    }
};

/*
Time and Space Complexity:

Time Complexity: O(n log n) due to sorting, where n is the number of matches.
Space Complexity: O(n) due to the hash map and lists used to store player information.
*/