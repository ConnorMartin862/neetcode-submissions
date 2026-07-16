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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (!root) {return results;}
        queue<TreeNode*> storage;
        storage.push(root);

        while (!storage.empty()) {
            int levelSize = storage.size();
            vector<int> temp;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* index = storage.front();
                if (index->left) {
                    storage.push(index->left);
                }
                if (index->right) {
                    storage.push(index->right);
                }
                temp.push_back(index->val);
                storage.pop();
            }
            results.push_back(temp);
        }
        return results;
    }
};
