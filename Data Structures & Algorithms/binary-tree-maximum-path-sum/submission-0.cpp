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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        int left = max(findMaxPath(root->left, result), 0);
        int right = max(findMaxPath(root->right, result), 0);
        result = max(result, left + right + root->val);
        return result;
    }

    int findMaxPath(TreeNode* root, int& result) {
        if (!root) {return 0;}
        int left = max(findMaxPath(root->left, result), 0);
        int right = max(findMaxPath(root->right, result), 0);
        result = max(result, left + right + root->val);
        return max(left + root->val, right + root->val);
    }
};
