// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
public:
vector<int> v;

    void preorder(TreeNode* root){
        if(!root){return;}
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       
        preorder(root);
        return v;
        
    }
};