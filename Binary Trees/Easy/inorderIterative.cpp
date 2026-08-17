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
//left root right
  vector<int> inorder(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st;
   TreeNode* node = root;
    while(true){
      if(node){
        st.push(node);
        node = node->left;
      }else{
        if(st.empty()) break;
        node = st.top();
        st.pop();
        ans.push_back(node->val);
        node = node->right;
      }
        }
        return ans;
  }
    int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
        vector<int> iterative = inorder(root);
        for(auto it: iterative){
            cout << it << " ";
        }
        cout << endl;
  return 0;

    }