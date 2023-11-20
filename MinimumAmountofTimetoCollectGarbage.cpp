/*
Problem Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/?envType=daily-question&envId=2023-11-20
*/

/*
Intuition:
The intuition behind the solution is to iterate through the array of garbage, keep track of the positions of Metal (M), Paper (P), and Glass (G) garbage units,
and calculate the total time required to collect each type of garbage. The travel array represents the time needed to travel between houses.

*/


/*
Algorithm:

1. Initialize variables total, G, M, and P to keep track of the total number of garbage units and the positions of G, M, and P garbage units.

2. Iterate through the array of garbage to find the positions of G, M, and P units and calculate the total number of garbage units.

3. Calculate the cumulative travel time between houses and update the travel array.

4. Add the travel time for each type of garbage if there is garbage of that type in any house.
   This is done to account for the travel time needed to reach the first house containing each type of garbage.

5. Return the total time calculated.

*/


/*
Learning from the problem :

The solution efficiently utilizes the travel array to account for the time needed to move between houses, updating it in a cumulative manner. 
Keeping track of the positions of each type of garbage helps in determining the travel time for each garbage truck.
The algorithm accounts for the fact that if a type of garbage is not present in any house, the corresponding travel time is not added.


*/


/******************************************************************************************************/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;   // Total time
        int total = 0;  // Total number of garbage units
        int n = garbage.size(); // Number of houses

        int G = 0;  // Position of Glass garbage
        int M = 0;  // Position of Metal garbage
        int P = 0;  // Position of Paper garbage

        // Iterate through each house
        for(int i=0; i<n; i++) {
            // Iterate through each garbage unit in the house
            for(int j=0; j < garbage[i].size(); j++) {
                // Update positions based on the type of garbage
                if(garbage[i][j] == 'M') {
                    M = i;
                } 
                else if(garbage[i][j] == 'P') {
                    P = i;
                }
                else {
                    G = i;
                }
                // Count the total number of garbage units
                total++;
            }
        }

        // Calculate cumulative travel time between houses
        for(int i=1; i<travel.size(); i++) {
            travel[i] += travel[i-1];
        }

        // Add travel time for each type of garbage if it is present in any house
        total += M > 0 ? travel[M-1] : 0;
        total += P > 0 ? travel[P-1] : 0;
        total += G > 0 ? travel[G-1] : 0;

        // Return the total time needed for garbage collection
        return total;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
The algorithm iterates through the array of garbage once, resulting in a time complexity of O(n),
where n is the total number of elements in the garbage array.

Space Complexity:
The solution uses a constant amount of extra space for variables (total, G, M, P), and the space complexity is O(1).
*/