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
 
  void inorder(vector<int>&temp, TreeNode*root){
    if(root==nullptr) return;
    inorder(temp,root->left);
    temp.push_back(root->val);
    inorder(temp,root->right);
  }

 vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(ans,root);
        return ans;
    }