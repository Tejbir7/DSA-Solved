#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
   bool isValid(TreeNode* root, long long low , long long high) {
        if(!root) return true;
        if(root->val <= low || root->val>= high) return false; //out of range
        return isValid(root->left,low,root->val) && isValid(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root){
        return isValid(root, LONG_MIN, LONG_MAX);
    }