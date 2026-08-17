#include<iostream>
#include<vector>
#include<queue>
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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
       return ans; 
    }
      int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
        vector<vector<int>> bfs = levelOrder(root);
        cout << "{" << " ";
        for(auto it: bfs ){
            cout << "[" ;
            for(auto t: it){
            cout << " "<< t<< " ";
        }
        cout << "]" << " ";
    }
    cout << "}" << endl;
      
  return 0;

    }