#include<iostream>
#include<vector>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  void postorder(vector<int>&temp, TreeNode*root){
    if(root==nullptr) return;
    postorder(temp,root->left);
    postorder(temp,root->right);
    temp.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode* root) {
          vector<int>ans;
        postorder(ans,root);
        return ans;
    }

    int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
        vector<int> dfsrecAns = postorderTraversal(root);
        for(auto it: dfsrecAns){
            cout << it << " ";
        }
        cout << endl;
  return 0;

    }