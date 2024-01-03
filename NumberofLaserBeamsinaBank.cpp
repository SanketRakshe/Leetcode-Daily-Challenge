/*

Problem Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03

Intuition:
- Imagine each device as a point emitting laser beams horizontally and vertically.
- Beams only form between devices on different rows, uninterrupted by devices in between.
- The number of beams between two rows equals the product of devices on each row.

Thought Process:
- Count devices on each row.
- Pair consecutive rows with devices and multiply their device counts for beams between them.
- Ignore rows without devices as they don't contribute beams.


Algorithm:
1. Initialize `prevDeviceCount` to 0 and `ans` to 0.

2. Iterate through each row:
   - Count devices in the current row (`currDeviceCount`).
   - If both current and previous rows have devices:
     - Add `prevDeviceCount * currDeviceCount` to `ans`.
   - Update `prevDeviceCount` to `currDeviceCount` for the next iteration.

3. Return `ans`.


Learning:

- Pattern Recognition: Identifying the pattern of device pairs forming beams and realizing it's a simple multiplication problem.
- Iterative Approach: Breaking down the problem into iterative steps to count devices and calculate beams efficiently.
- Clear Variables: Using descriptive variable names to enhance code readability.
- Conciseness: Writing a compact solution that directly addresses the problem's core logic.
- Attention to Constraints: Understanding the problem's constraints (e.g., matrix dimensions and character values) to ensure a valid solution.


Code:
*/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();  // Number of rows in the bank
        int prevDeviceCount = 0;  // Number of security devices in the previous row
        int ans = 0;  // Total number of laser beams

        // Iterate through each row of the bank
        for (int i = 0; i < n; i++) {
            int currDeviceCount = 0;  // Number of security devices in the current row

            // Count the number of security devices in the current row
            for (char &ch : bank[i]) {
                if (ch == '1') {
                    currDeviceCount++;
                }
            }

            // Update the total number of laser beams
            ans += (prevDeviceCount * currDeviceCount);

            // If there are security devices in the current row, update prevDeviceCount
            if (currDeviceCount != 0) {
                prevDeviceCount = currDeviceCount;
            }
        }

        // Return the final result
        return ans;
    }
};



/*
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns (due to iterating through the matrix and counting devices in each row).
Space Complexity: O(1), as we only use a constant amount of extra space for variables, regardless of the input size.

*/

