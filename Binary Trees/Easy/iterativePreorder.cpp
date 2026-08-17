#include<iostream>
#include<vector>
#include<stack>
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

  vector<int> preorderTraversal(TreeNode* root){
    vector<int> preorder;
    if(!root) return preorder;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
        }
        return preorder;
  }

      int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
        vector<int> dfsrecAns = preorderTraversal(root);
        for(auto it: dfsrecAns){
            cout << it << " ";
        }
        cout << endl;
  return 0;

    }