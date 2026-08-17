#include<iostream>
#include<climits>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  int maxPath(TreeNode* root, int &maxi){
    if(!root) return 0;

    int left = max(0, maxPath(root->left,maxi));
    int right = max(0,maxPath(root->right,maxi));
    maxi = max(maxi,root->val+left+right);
    return root->val+ max(left,right);
  }

  int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    maxPath(root,maxi);
    return maxi;

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
        
        int used = maxPathSum(root);
     
        cout << used ;
  return 0;

    }