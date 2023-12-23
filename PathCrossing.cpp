/*
Problem Link: 


Intuition and Thought Process:
The problem requires determining whether a path crosses itself by keeping track of the visited coordinates.
The idea is to simulate the movement on a 2D plane by updating the coordinates based on the characters in the path.
The set is used to store the visited coordinates to check for crossings.


Algorithm:

1. Initialize a set to store visited coordinates.
2. Initialize the starting coordinates at (0, 0) and insert into the set.
3. Traverse each character in the path:
    - Update the coordinates based on the current character.
    - Convert the coordinates to a string and check if it's in the set.
    - If yes, return true as the path crosses itself.
    - If no, insert the coordinates into the set.
4. If the traversal completes without finding a crossing, return false.



Learning from the problem :

The problem emphasizes efficient coordinate tracking using sets to identify crossings,
showcasing the value of clear algorithmic insight, pattern recognition, and systematic problem-solving.


/******************************************************************************************************/

class Solution {
public:
    bool isPathCrossing(string path) {
        // Create a set to store the visited coordinates as strings
        unordered_set<string> st;

        // Initialize the starting point at the origin (0, 0)
        int x = 0;
        int y = 0;

        // Convert the current coordinates to a string and insert into the set
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);

        // Traverse through each character in the path
        for(char &ch : path) {
            // Update the coordinates based on the current character
            if(ch == 'E') {
                x += 1;
            } else if(ch == 'W') {
                x -= 1;
            } else if(ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }

            // Convert the updated coordinates to a string
            key = to_string(x) + "_" + to_string(y);

            // Check if the current coordinates have been visited before
            if(st.find(key) != st.end()) {
                return true;  // If yes, the path crosses itself
            }

            // Insert the current coordinates into the set
            st.insert(key);
        }

        // If no crossing is found, return false
        return false;
    }
};



/******************************************************************************************************/

/*

Complexity:

- Time Complexity: O(N), where N is the length of the input path.

- Space Complexity: O(N), as the set stores the visited coordinates.


*/