#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left,*right;
        int val;
        TreeNode(int val){
            this->val=val;
            this->left=nullptr;
            this->right=nullptr;
        }
};
TreeNode* createTree(vector<int>& tree,int i,int n){
    if(i>=n)return nullptr;
    TreeNode* root=new TreeNode(tree[i]);
    root->left=createTree(tree,2*i+1,n);
    root->right=createTree(tree,2*i+2,n);
    return root;
}
void inorder(TreeNode* root,vector<vector<int>>& ans){
    if(!root)return;
    inorder(root->left,ans);
    ans[0].push_back(root->val);
    inorder(root->right,ans);
}
void preorder(TreeNode* root,vector<vector<int>>& ans){
    if(!root)return;
    ans[1].push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
void postorder(TreeNode* root,vector<vector<int>>& ans){
    if(!root)return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans[2].push_back(root->val);
}
int main(){
    int n;
    cin>>n;
    vector<int> tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    TreeNode* root=createTree(tree,0,n);
    vector<vector<int>> ans(3);
    inorder(root,ans);
    preorder(root,ans);
    postorder(root,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}