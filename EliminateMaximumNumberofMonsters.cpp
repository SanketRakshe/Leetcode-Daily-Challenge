/*
Problem Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/?envType=daily-question&envId=2023-11-07
*/

/*

Intuition:

Hi there, 😄

Let's dive🤿 deep into our today's problem.

The problem describes a scenario where you are defending your city from monsters approaching at a constant speed.
You have a weapon that takes one minute to charge and can eliminate a single monster.
The goal is to determine the maximum number of monsters you can eliminate before losing (i.e., before any monster reaches the city).

*/



/*

Algorithm:

1) Create vector named as vec which represent the initial distances of the monsters respectively.
2) Calculate the time each monster takes to reach the city by dividing its initial distance by its speed and rounding up to the nearest minute (using ceil).
3) Sort the vec array, which contains these calculated times.
4) Initialize a count of eliminated monsters to 1 and set the time_passed to 1, indicating that the first minute has passed.
5) Iterate through the vec array from the second element to the end:
    -If the time it takes for the current monster to reach the city minus the time passed is less than or equal to 0, you cannot eliminate this monster before it reaches the city.
     In this case, return the current count of eliminated monsters.
    -If you can eliminate the current monster before it reaches the city, increment the count and the time passed.
6) After the loop, return the count of eliminated monsters.

*/


/******************************************************************************************************/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> vec(n);

        for(int i=0; i<n; i++) {
            vec[i] = ceil((float) dist[i] / speed[i]);
        }

        sort(vec.begin(), vec.end());

        int count = 1;
        int timePassed = 1;

        for(int i=1; i<n; i++) {
            if(vec[i] - timePassed <= 0) {
                return count;
            }
            count++;
            timePassed++;
        }
        return count;
    }
};


/******************************************************************************************************/

/*

Complexity
Time complexity: 
The most time-consuming part of the algorithm is sorting the vec array, which has a time complexity of O(nlogn) due to the sorting operation.
The subsequent loop has a time complexity of O(n). Thus, the overall time complexity is O(nlogn).


Space Complexity:

The space complexity is primarily determined by the vec vector, which has the same size as the input arrays dist and speed.
Therefore, the space complexity is O(n).
*/