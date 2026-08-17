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
     TreeNode* buildT(vector<int>&preOrder, int preStart, int preEnd,
    vector<int>&inOrder, int inStart, int inEnd, unordered_map<int,int>&inMap){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode *root = new TreeNode(preOrder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot- inStart;

        root->left = buildT(preOrder,preStart+1,preStart+numsLeft,
        inOrder,inStart,inRoot-1,inMap);
        root->right = buildT(preOrder,preStart+numsLeft+1,preEnd,
        inOrder,inRoot+1,inEnd,inMap);
        return root;
    }
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int>inMap;
       for(int i=0;i<inorder.size();++i){
        inMap[inorder[i]] =i;
       }
       TreeNode* root = buildT(preorder,0,preorder.size()-1, inorder,0, inorder.size()-1, inMap);
       return root;

    }
 