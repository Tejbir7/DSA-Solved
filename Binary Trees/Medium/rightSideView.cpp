#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    queue <TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        
        for(int i=0;i<size;++i){
            TreeNode* node = q.front();
            q.pop();
            if(i==0) ans.push_back(node->val);
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
    }
    return ans;        
    }

    //approach 2
    void dfs(TreeNode* root, int level, vector<int> & ans){
    if(!root) return;
    if(level == ans.size()){
        ans.push_back(root->val);
       }   
   
    if(root->right) dfs(root->right,level+1,ans);
    if(root->left) dfs(root->left,level+1,ans);
  }
  vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }