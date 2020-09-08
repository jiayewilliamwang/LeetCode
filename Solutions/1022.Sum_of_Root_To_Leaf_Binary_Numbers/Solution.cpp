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
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, "");
    }
    
    int helper(TreeNode* root, string cur) {
        if (!root) 
            return 0;
        if (root->left == root->right)
            return stoi(cur + to_string(root->val), nullptr, 2);
        int left = helper(root->left, cur + to_string(root->val));
        int right = helper(root->right, cur + to_string(root->val));
        return left + right;
    }
};
