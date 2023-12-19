/*
Problem Link: https://leetcode.com/problems/image-smoother/description/?envType=daily-question&envId=2023-12-19


Intuition and Thought Process:

The problem asks for applying a smoothing filter to each cell of the given image matrix.
The smoothing filter is a 3x3 matrix, and for each cell, you take the average of the cell and its eight neighboring cells.
If a neighboring cell is out of bounds, you don't include it in the average.

The algorithm iterates through each cell in the matrix, calculates the sum of the cell and its valid neighbors,
and then computes the average by dividing the sum by the count of valid neighbors. This average is rounded down, as specified in the problem.


Algorithm:

1. Initialize a 3x3 matrix representing the directions to get the neighboring cells.
2. Iterate through each cell in the input matrix.
3. For each cell, iterate through its 3x3 neighborhood using the predefined directions.
4. For each valid neighbor, accumulate the sum and increment the count.
5. Calculate the average by dividing the sum by the count.
6. Assign the rounded-down average to the corresponding cell in the result matrix.



Learning from the problem :

1. Iterative Approach: The solution uses a straightforward iterative approach to solve the problem.
   It demonstrates the use of nested loops to traverse the matrix and calculate the average for each cell.

2. Boundary Checking: The solution includes boundary checking to ensure that only valid neighboring cells are considered in the average calculation.
   This prevents index out-of-bounds errors.

3. Direction Matrix: The use of a predefined direction matrix simplifies the code and makes it easier to handle the neighbors.
   It also improves code readability.

4. Rounding Down: The problem specifies rounding down the average. This is achieved by directly dividing integers in C++,
   as integer division in most programming languages truncates the decimal part.




/******************************************************************************************************/

class Solution {
public:
    // Define the 3x3 directions matrix for neighboring cells.
    vector<vector<int>> directions {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        // Initialize a matrix to store the smoothed image.
        vector<vector<int>> result(m, vector<int>(n));

        // Iterate through each cell in the input matrix.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;

                // Iterate over all possible nine indices.
                for(auto &it : directions) {
                    // Calculate the indices of the neighboring cell.
                    int delta_i = i + it[0];
                    int delta_j = j + it[1];

                    // Check if the neighboring cell is within bounds.
                    if (0 <= delta_i && delta_i < m && 0 <= delta_j && delta_j < n) {
                        // Accumulate the sum and increment the count.
                        sum += img[delta_i][delta_j];
                        count += 1;
                    }
                }

                // Calculate the average and assign it to the result matrix.
                result[i][j] = sum / count;
            }
        }

        // Return the smoothed image.
        return result;
    }
};


/******************************************************************************************************/

/*

Complexity
Time Complexity: O(m * n) where 'm' is the number of rows and 'n' is the number of columns in the input matrix.
This is because you have nested loops that iterate through each cell of the matrix, and the inner loop has a constant number of iterations (9 in this case).


Space Complexity: The space complexity is O(m * n) as the algorithm uses an additional matrix of the same size as the input matrix to store the results.

*/