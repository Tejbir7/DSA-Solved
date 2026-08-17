#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  void dfs(TreeNode* root, int level, vector<vector<int>> & ans){
    if(!root) return;
    if(level == ans.size()){
        ans.push_back({});
    }
    ans[level].push_back(root->val);
    if(root->left) dfs(root->left,level+1,ans);
    if(root->right) dfs(root->right,level+1,ans);
  }