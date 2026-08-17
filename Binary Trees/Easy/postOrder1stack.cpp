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

  vector<int> postOrder(TreeNode*root){
    vector<int> ans;
    if(!root) return ans;
    TreeNode* curr = root;
    stack<TreeNode*> st;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }else{
            TreeNode* temp = st.top()->right;
            if(!temp){// for left insertion 
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right){ // right insertion
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                }
            }else curr = temp;
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
      
        vector<int> postOrd = postOrder(root);
        for(auto it: postOrd){
            cout << it << " ";
        }
        cout << endl;
  return 0;

    }