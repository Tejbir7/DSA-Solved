#include<iostream>
#include<vector>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 bool root2Node(TreeNode* root, int target, vector<int>&path){
    if(!root) return false;
    path.push_back(root->val);
    if(root->val==target) return true;
  
    if(root2Node(root->left,target,path )||root2Node(root->right,target,path)) return true;
    path.pop_back();
    return false;

 }
 vector<int> root2NodePath(TreeNode*root, int target){
    vector<int>ans;
    root2Node(root,target,ans);
    return ans;
 }