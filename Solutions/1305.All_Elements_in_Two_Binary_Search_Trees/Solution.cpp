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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>r1, r2;
        inorder(r1, root1);
        inorder(r2, root2);
        
        vector<int> res = r1;
        res.insert(res.end(), r2.begin(), r2.end());
        sort(res.begin(), res.end());
        return res;
        
    }
    
    void inorder(vector<int>& r, TreeNode* tree) {
        if (!tree) return;
        inorder(r, tree->left);
        r.push_back(tree->val);
        inorder(r, tree->right);
    }
};
