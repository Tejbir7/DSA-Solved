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
  void inorder(TreeNode*root, int& k, int &smallest){
    if(!root || !k) return;
    inorder(root->left,k,smallest);
    k--;
    if(!k) smallest = root->val; return;
    inorder(root->right,k,smallest);
  }
   int kthSmallest(TreeNode* root, int k) {
        int smallest = 0;
        inorder(root,k,smallest);
        return smallest;
    }