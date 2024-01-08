/*
Problem Intuition:
The problem involves a binary search tree (BST) and requires finding the sum of values of nodes within a given range [low, high].

Thought Process:
1. Recursive Approach: The solution uses a recursive approach to traverse the BST.
2. Range Checking: At each node, it checks if the node's value is within the given range [low, high].
3. Sum Calculation: If the node's value is within the range, it adds the value to the sum.
   If the value is less than low, it explores the right subtree. If the value is greater than high, it explores the left subtree.

Algorithm:
1. If the root is null, return 0 (base case).
2. If the node's value is within the range [low, high], add the node's value to the sum.
3. If the node's value is less than low, recursively call the function on the right subtree.
4. If the node's value is greater than high, recursively call the function on the left subtree.
5. Return the sum.
*/

//Code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        if (low <= root->val && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + 
            rangeSumBST(root->right, low, high);
        } 
        else if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        } 
        else {
            return rangeSumBST(root->left, low, high);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        if (low <= root->val && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + 
            rangeSumBST(root->right, low, high);
        } 
        else if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        } 
        else {
            return rangeSumBST(root->left, low, high);
        }
    }
};



/*
Learning:
1. BST Properties: Leveraging the properties of a binary search tree where values in the left subtree are smaller,
   and values in the right subtree are larger.
2. Recursive Approach: Using recursion to traverse the tree and solve the problem in a divide-and-conquer manner.
3. Efficiency: The solution efficiently skips unnecessary branches based on the range and BST properties.

Time Complexity:
The time complexity is O(N), where N is the number of nodes in the BST. In the worst case, we may have to visit all nodes.

Space Complexity:
The space complexity is O(H), where H is the height of the tree. In the worst case (skewed tree),
the space complexity approaches O(N), but in a balanced tree, it is O(log N). This is due to the recursion stack.
*/