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


   int maxDepth(TreeNode* root) {
    if(!root) return 0;
      int leftH = maxDepth(root->left);
      int rightH = maxDepth(root->right);
      if(leftH==-1 || rightH==-1) return -1;

      if(abs(leftH-rightH)>1) return -1;
        return 1 + max(leftH, rightH);
    }
      bool isBalanced(TreeNode* root) {
        int check = maxDepth(root);
       return (check!=-1);
    }
