/*
Problem Description:
The problem asks for a list of integers within a given range `[low, high]` where each digit in the number is one more than the previous digit.

Intuition:
1. We need to generate sequential digits.
2. Start with the digits 1 through 8, as these are the only digits that can form sequential numbers 
   (9 is not possible to have a digit after it that is one more than itself).
3. Use a queue to generate numbers by appending the next digit if it is one more than the last digit.
4. Enqueue and dequeue until the queue is empty, and collect the valid numbers within the given range.

Algorithm Steps:
1. Initialize a queue with digits 1 through 8.
2. While the queue is not empty, dequeue a number and check if it falls within the given range `[low, high]`.
3. If yes, add it to the result vector.
4. Extract the last digit of the dequeued number.
5. If the next digit (last digit + 1) is less than or equal to 9, enqueue the new number formed by appending the next digit.
6. Repeat steps 2-5 until the queue is empty.

Learning:
1. Realize that only digits 1 through 8 can be the starting point for sequential digits.
2. Understand the importance of using a queue to explore all possible combinations in a systematic manner.
3. Observe that the solution avoids unnecessary exploration of numbers outside the given range.
*/

//Code:

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        for(int i=1; i<=8; i++) {
            q.push(i);
        }

        vector<int> result;

        while(!q.empty()) {
            int temp = q.front();
            q.pop();

            if(temp >= low && temp <= high) {
                result.push_back(temp);
            }

            int lastDigit = temp % 10;

            if(lastDigit + 1 <= 9) {
                q.push(temp * 10 + (lastDigit + 1));
            }
        }
        return result;
    }
};

/*
Time Complexity: O(N), where N is the number of sequential digit numbers within the range. Each number is enqueued and dequeued exactly once.

Space Complexity: O(N), The queue can hold up to N numbers in the worst case, representing all valid sequential digit numbers within the range.
*/
