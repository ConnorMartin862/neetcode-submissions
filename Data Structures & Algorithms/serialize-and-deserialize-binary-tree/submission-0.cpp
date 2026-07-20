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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* root, string& result) {
        if (!root) {
            result += 'N';
            result += ',';
        }
        else {
            result += to_string(root->val);
            result += ',';
            preorder(root->left, result);
            preorder(root->right, result);
            return;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return helper(data, index);
    }

    TreeNode* helper (string& data, int& index) {
        if (data[index] == 'N') {
            index += 2;
            return nullptr;
        }

        int count = 0;
        while (data[index] != ',') {
            index++;
            count++;
        }
                
        int value = stoi(data.substr(index - count, count));
        TreeNode* root = new TreeNode(value);
        index++;
        root->left = helper(data, index);
        root->right = helper(data, index);
        return root;
    }
};
