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

  void dfsSum(TreeNode* root, long long &totalSum){
    if(!root) return;
    totalSum = totalSum+ root->val;
    dfsSum(root->left,totalSum);
    dfsSum(root->right,totalSum);
  } 
  
  long long maxPsum(TreeNode*root, long long totalSum, long long &best){
    if(!root) return 0;
    long long left = maxPsum(root->left,totalSum, best);
    long long right = maxPsum(root->right,totalSum, best);

    long long subTree = left+ right + root->val;
    best = max(best, subTree*(totalSum-subTree));
    return subTree;
  }

  int maxProduct(TreeNode* root) {
    long long totalSum = 0;
    dfsSum(root,totalSum);
    long long best = 0;
    maxPsum(root,totalSum,best);
    const int MOD = 1e9 + 7;
    return (int) (best%MOD);    
     }

      int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
        int maxi = maxProduct(root);
     
        cout << maxi ;
  return 0;

    }