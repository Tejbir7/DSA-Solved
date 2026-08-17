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
   TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* Attach = new TreeNode(val);
    if(!root) return Attach;
    TreeNode* curr = root;
    while(true){
        if(curr->val < val){
            if(!curr->right){ curr->right = Attach;
            break;
            }else curr = curr->right;
        }else{
            if(!curr->left){
                curr->left = Attach;
                break;
            } else curr = curr->left;
        }
    }
      return root;  
    }