#include<iostream>
#include<unordered_map>
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
  //FLAwED LOGICCCC WONT WORKKKK!!!!!!!!!!!!!


//   void swapNodes(TreeNode* first, TreeNode*second){
//      int temp = first->val;
//         first->val = second->val;
//         second->val = temp;
//         return;
//   }
//   void recover(TreeNode*root, long long low, long long high, unordered_map<int, TreeNode*> & mpp){
//     if(!root) return;
//     if(root->val <= low){
//         TreeNode* node = mpp[low];
//         swapNodes(node,root);  
//         return;     
//     }
//     else if(root->val>= high){
//         TreeNode* node = mpp[high];
//         swapNodes(node,root);
//         return;
//     }
//     mpp[root->val] = root;
//     recover(root->left,low,root->val,mpp);
//     recover(root->right,root->val,high,mpp);
//   }
//       void recoverTree(TreeNode* root) {
//         unordered_map<int, TreeNode*> mpp;
//         recover(root, LONG_MIN,LONG_MAX,mpp);
//         return;        
//     }
TreeNode* first = nullptr;
TreeNode* second = nullptr;
TreeNode* prevNode = nullptr;

void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);

    if (prevNode && root->val < prevNode->val) {
        if (!first) first = prevNode;
        second = root;
    }

    prevNode = root;

    inorder(root->right);
}

void recoverTree(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val);
}