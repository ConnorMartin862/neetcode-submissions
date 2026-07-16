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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> storage;
        for (int i = 0; i < inorder.size(); i++) {
            storage[inorder[i]] = i;
        }

        int preIndex = 0;

        return helper(preorder, storage, preIndex, 0, preorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& storage, int& preIndex, int start, int end) {
        if (start > end) {return nullptr;}
        int rootVal = preorder[preIndex];
        TreeNode* base = new TreeNode(rootVal);
        int mid = storage[rootVal];
        preIndex++;
        base->left = helper(preorder, storage, preIndex, start, mid - 1);
        base->right = helper(preorder, storage, preIndex, mid + 1, end);
        return base;
    }
};
