// morris inorder traversal


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // using morris traversal method
        vector<int> v;
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                v.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    v.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return v;
    }
};