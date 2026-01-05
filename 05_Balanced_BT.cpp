// Given a binary tree, determine if it is height-balanced.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true



// GFG Solution only

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
    int helper(TreeNode* node) {
        if (node == NULL) return 0;
        return 1 + max(helper(node->left), helper(node->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int lHeight = helper(root->left);
        int rHeight = helper(root->right);

        if (abs(lHeight - rHeight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
