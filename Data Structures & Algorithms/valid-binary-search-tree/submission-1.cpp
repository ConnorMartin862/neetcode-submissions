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
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return helper(root, prev);
    }

    bool helper(TreeNode* root, long long& prev) {
        if (!root) {return true;}
        if (!helper(root->left, prev)) {return false;}
        if (root->val <= prev) {return false;}
        prev = root->val;
        if (!helper(root->right, prev)) {return false;}
        return true;
    }
};
