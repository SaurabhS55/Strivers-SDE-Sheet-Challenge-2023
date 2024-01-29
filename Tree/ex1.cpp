//Binary Tree Inorder Traversal
//leetcode - 94
//https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(!root){return;}
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return v;
    }
};