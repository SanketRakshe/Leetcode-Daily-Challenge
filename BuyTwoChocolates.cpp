/*
Problem Link: https://leetcode.com/problems/buy-two-chocolates/?envType=daily-question&envId=2023-12-20


Intuition and Thought Process:

1. We want to minimize the sum of two chocolate prices, so ideally, we want to pick the two cheapest chocolates.
2. We need to handle the case where buying the two cheapest chocolates would exceed our initial amount of money.



Algorithm:

1. Initialize two variables `minPrice` and `secMinPrice` to store the minimum and second minimum prices.
2. Iterate through the array `prices`.
    - If the current price is less than `minPrice`, update both `minPrice` and `secMinPrice`.
    - If the current price is greater than `minPrice` but less than `secMinPrice`, update only `secMinPrice`.
3. Check if the sum of the two minimum prices is greater than the initial amount of money. If so, return the initial money.
4. Calculate the leftover money by subtracting the sum of the two minimum prices from the initial money.
5. Return the leftover money.




Learning from the problem :

- The key insight is to identify and keep track of the two cheapest chocolates while iterating through the prices array.
- By selecting the two minimum prices, we ensure that we minimize the cost of buying two chocolates.
- The comparison and updating logic in the loop ensures that we have the correct values for `minPrice` and `secMinPrice`.



/******************************************************************************************************/


class Solution {
public:
   int buyChoco(vector<int>& prices, int money) {
       // Initialize variables to track the two cheapest chocolates
       int minPrice = INT_MAX;  
       int secMinPrice = INT_MAX;  

       // Track the two cheapest chocolates for minimal cost
       for (int &price : prices) {
           if (price < minPrice) {
               // Found a new minimum price, update both variables
               secMinPrice = minPrice;
               minPrice = price;
           } else if (price < secMinPrice) {
               // Update second minimum price only
               secMinPrice = price;
           }
       }

       // Check if buying the two cheapest chocolates is affordable
       if (minPrice + secMinPrice > money) {
           // Cannot buy without going into debt, return initial amount
           return money;
       }

       // Calculate and return the leftover money after buying the two cheapest
       return money - (minPrice + secMinPrice);
   }
};



/******************************************************************************************************/

/*

Complexity
Time Complexity: O(N), where N is the number of chocolates (length of the `prices` array). We iterate through the array once.

Space Complexity: O(1), as we use a constant amount of space (two variables).


*/