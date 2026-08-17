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

  vector<int> postOrder(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }
while(!st2.empty()){
    ans.push_back(st2.top()->val);
    st2.pop();
} 
return ans;
}
 int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
        vector<int> postOrd = postOrder(root);
        for(auto it: postOrd){
            cout << it << " ";
        }
        cout << endl;
  return 0;

    }