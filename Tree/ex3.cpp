// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
vector<int> v;
void postorder(TreeNode* root){
    if(!root){return;}
    postorder(root->left);
    postorder(root->right);
    v.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return v;
    }
};