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

  vector<int> MorrisInorder(TreeNode* root){
    if(!root) return {};
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr){
        if(!curr->left){ //No left direct
            inorder.push_back(curr->val);
            curr = curr->right;
        }else{
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr ){ //rightmost of left
                prev = prev->right;
            }
            if(prev->right == nullptr){ //reached the end
                prev->right = curr;
                curr = curr->left;
            }else{ //break the thread and store
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
return inorder;
  }