#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
   TreeNode* buildT(const vector<int>&postOrder, int postLeft, int postRight,
   const vector<int>&inOrder, int inLeft, int inRight, unordered_map<int,int>&inMap){
     if(postLeft>postRight || inLeft>inRight) return nullptr;
      TreeNode*root = new TreeNode(postOrder[postRight]);
      int inRoot = inMap[root->val];
      int Left = inRoot-inLeft;
      root->left = buildT(postOrder,postLeft,postLeft+Left-1,
      inOrder,inLeft,inRoot-1,inMap);
      root->right = buildT(postOrder,postLeft+Left,postRight-1,
        inOrder,inRoot+1,inRight, inMap);

        return root;
    }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> inMap;
    for(int i=0;i<inorder.size();++i){
      inMap[inorder[i]] =i;
    }
    TreeNode* root = buildT(postorder,0,postorder.size()-1, 
  inorder, 0, inorder.size()-1, inMap);
  return root;        
    }
    
   





    