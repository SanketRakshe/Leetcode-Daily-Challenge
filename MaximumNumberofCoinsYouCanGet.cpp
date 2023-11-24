/*
Problem Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/?envType=daily-question&envId=2023-11-24
*/

/*
Intuition:
The intuition behind this solution lies in adopting a greedy strategy by selecting piles in a sorted order.
Sorting allows efficient identification of the second-largest pile in each triplet,
ensuring that you consistently acquire a substantial number of coins. By strategically positioning pointers and iteratively picking piles,
the algorithm optimizes the distribution of coins among you, Alice, and Bob, ultimately maximizing your total.
*/


/*
Algorithm:

1. Sort the given `piles` array in ascending order.

2. Initialize pointers for Bob (`Bob`), yourself (`Me`), and Alice (`Alice`) at appropriate positions in the sorted array.

3. Iterate through the array while there are still piles left for you to pick.

4. In each iteration, add the number of coins in the pile at the `Me` position to your total (`result`).

5. Move the pointers accordingly: `Bob++`, `Alice -= 2`, `Me -= 2`. This ensures that you, Alice, and Bob pick piles in the required order.

6. Continue the process until you have picked all the piles.

*/


/*
Learning from the problem :
1. Greedy Strategy: This problem involves a greedy strategy where you make locally optimal choices at each step (picking the second-largest pile)
   to achieve a globally optimal solution (maximizing the total number of coins you end up with).
2. Sorting for Optimization: Sorting the array allows you to easily identify the second-largest pile in each triplet,
   simplifying the decision-making process during the iteration.
*/


/******************************************************************************************************/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(piles.begin(), piles.end());

        int Bob = 0;
        int Me = n-2;
        int Alice = n-1;

        int result = 0;
        while(Me > Bob) {

            result += piles[Me];

            Bob++;
            Alice -= 2;
            Me -= 2;
        }
        return result;
    }
};


/******************************************************************************************************/

/*
Complexity

Time complexity: 
The most time-consuming operation is sorting the array, which takes O(n log n) time.
The iteration through the sorted array is O(n). Overall time complexity is dominated by the sorting step: O(n log n).

Space Complexity:
The space complexity is O(1) since the algorithm uses a constant amount of extra space,
regardless of the input size (only a few variables are used).
*/