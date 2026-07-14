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
        queue<TreeNode*> storage;
        vector<vector<int>> result;
        if (root) {storage.emplace(root);}
        while (!storage.empty()) {
            int a = storage.size();
            vector<int> temp;
            for (int i = 0; i < a; i++) {
                if (storage.front()->left) {
                    storage.emplace(storage.front()->left);
                }
                if (storage.front()->right) {
                    storage.emplace(storage.front()->right);
                }
                temp.push_back(storage.front()->val);
                storage.pop();
            }
            result.push_back(temp);
        }
        return result;
    }
};
