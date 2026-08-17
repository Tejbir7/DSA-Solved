#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  void markParents(TreeNode*root, unordered_map<TreeNode*,TreeNode*>&mpp){
    queue<TreeNode*>q;
    q.push(root);
 
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            mpp[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            mpp[curr->right]= curr;
            q.push(curr->right);
        }

    }
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markParents(root,parent_track);   //parent marking

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target); //start from target and exploree
        visited[target] = true;

        int currLevel = 0;
        while(!q.empty()){
            int size = q.size();
            if(currLevel++ == k) break;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track.count(curr) && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }
 vector<int>result;
 while(!q.empty()){
    TreeNode* curr = q.front();
    q.pop();
    result.push_back(curr->val);
 }
return result;        
    }