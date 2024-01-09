/*
Problem Intuition:

- The key idea is to focus on the **leaf values** and their **order**, not the overall structure of the trees.
- Trees with different structures can still be leaf-similar if their leaf sequences match.

Thought Process:
1. Identify the leaf nodes:Traverse each tree to find the leaf nodes, which are nodes with no children.
2. Capture leaf values in order:Collect the values of these leaf nodes in the order they are encountered during the traversal.
   This preserves the left-to-right sequence.
3. Compare sequences:Compare the two sequences of leaf values from the two trees. If they are identical, the trees are leaf-similar.

Algorithm:

1. Recursive Traversal (Solve function):
   - Base Case: If the current node is null, return (no leaf).
   - If the current node is a leaf (has no children):
     - Append its value to the string representing the leaf sequence.
   - Otherwise, recursively traverse its left and right subtrees.

2. Leaf Similarity Check (leafSimilar function):
   - Create two empty strings to store the leaf sequences of the two trees.
   - Call Solve for each tree to construct their respective leaf sequences.
   - Compare the two strings for equality. If equal, return true; otherwise, return false.
*/

//Code:

class Solution {
public:
    void preOrder(TreeNode* root, string& s) {
        if(root == NULL) 
        return;
        
        if(root->left == NULL && root->right == NULL) {
            s += to_string(root->val) + "_";
            return;
        }
        
        preOrder(root->left, s);
        preOrder(root->right, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1 = "";
        string s2 = "";
        
        preOrder(root1, s1);
        preOrder(root2, s2);
        
        return s1==s2;
    }
};


/*
Time Complexity: O(n), where n is the number of nodes in the larger tree. This is due to the recursive traversal, which visits each node once.

Space Complexity: O(h), where h is the height of the deeper tree. The space used for the recursive calls and the string concatenation depends on the height of the tree.


*/