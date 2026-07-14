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
        
        while (true) {
            int a = low->val;
            int b = high->val;
            if ((result->val > a && result->val < b) || (result->val == a || result->val == b)) {
                break;
            } else if (!result->right || (result->val > a && result->val > b)) {
                result = result->left;
            } else {
                result = result->right;
            }
        }
        return result;
    }
};
