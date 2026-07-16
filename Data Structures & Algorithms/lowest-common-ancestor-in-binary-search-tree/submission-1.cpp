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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = root;
        TreeNode* high;
        TreeNode* low;
        if (p->val > q->val) {
            high = p;
            low = q;
        } else {
            high = q;
            low = p;
        }

        while (!(result->val >= low->val && result->val <= high->val)) {
            if (high->val < result->val) {
                result = result->left;
            } else if (low->val > result->val) {
                result = result->right;
            }
        }
        return result;
    }
};
