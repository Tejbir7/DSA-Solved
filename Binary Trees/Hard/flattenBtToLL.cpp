#include<iostream>
#include<vector>
#include<stack>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  //Approach 1

   void solve(TreeNode* root, TreeNode* &prev) {
        if(!root) return;
        solve(root->right, prev);
        solve(root->left, prev);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    void flatten(TreeNode* root) {
    TreeNode* prev = nullptr;
    solve(root, prev);
}

//approach 2 by stack:
void flatten(TreeNode* root){
    if(!root) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
      TreeNode* curr = st.top();
      st.pop();
      if(curr->right) st.push(curr->right);
      if(curr->left) st.push(curr->left);
      if(!st.empty()){
        curr->right = st.top();
        curr->left = nullptr;
      }
    }
}

//approach 3 by morris traversal
void flatten(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
          TreeNode* prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}