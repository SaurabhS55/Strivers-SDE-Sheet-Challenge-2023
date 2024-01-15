// create binary tree
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
int main()
{
    int n;
    cin>>n;
    vector<int> tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    TreeNode* t=createTree(tree,0,n);
    cout<<t->val;
    return 0;
}