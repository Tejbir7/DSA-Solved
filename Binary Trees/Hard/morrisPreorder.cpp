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

  vector<int> MorrisPreorder(TreeNode* root){
    if(!root) return {};
    vector<int> preorder;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){
            preorder.push_back(curr->val); //No left
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!= curr){ //Go rightmost of left
                prev = prev->right;
            }
            if(prev->right == nullptr){ //make connection
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }else{
                prev->right = nullptr; //break connection
                curr = curr->right;
            }
        }
    }
return preorder;
  }