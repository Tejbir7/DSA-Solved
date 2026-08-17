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
      int leftDepth = maxDepth(root->left);
      int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* left1 = new TreeNode(6);
        TreeNode*right1 = new TreeNode(7);
        root->left = left1;
        root->right = right1;
        TreeNode* left2 = new TreeNode(88);
        TreeNode*right2 = new TreeNode(99);
        left1->left = left2;
        left2->right = right2;
        int maxDep = maxDepth(root);
     
        cout << maxDep ;
  return 0;

    }