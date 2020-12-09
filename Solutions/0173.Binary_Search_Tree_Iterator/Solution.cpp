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
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    helper(root);
    pointer_ = 0;
  }
  
  void helper(TreeNode* root) {
    if (!root) {
      return;
    } else {
      helper(root->left);
      inorder_.push_back(root->val);
      helper(root->right);
    }
  }
    
  int next() {
    return inorder_[pointer_++];
  }
    
  bool hasNext() {
    return pointer_ != inorder_.size();
  }
  
private:
  vector<int> inorder_;
  int pointer_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
