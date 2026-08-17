#include<iostream>
#include<utility>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  pair<TreeNode*, int> lca(TreeNode*root){
    if(!root) return {nullptr,0};

    auto left = lca(root->left);
    auto right = lca(root->right);

    if(left.second==right.second) return {root,left.second+1};
    else if(left.second>right.second) return {left.first,left.second+1};
    else return {right.first,right.second+1};
  }
   TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca(root).first;
    }