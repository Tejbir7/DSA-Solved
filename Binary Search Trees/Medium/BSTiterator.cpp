#include<iostream>
#include<stack>
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
  class BSTIterator {
    private:
    stack<TreeNode*> st;
     void pushAllLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
    pushAllLeft(root);
}
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(node->right){
           pushAllLeft(node->right);
        }
        return node->val;        
    }
    
    bool hasNext() {
        return !st.empty();
    }
};