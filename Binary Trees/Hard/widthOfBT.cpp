#include<iostream>
#include<vector>
#include<algorithm>
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
  //Never try to use this approach its complete wrong approach
    // int widthOfBinaryTree(TreeNode* root) {
    //     if(!root) return 0;
    //     int count = 0;
    //     int ans = 0;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         int size = q.size();

    //         for(int i=0;i<size;++i){
    //             TreeNode* node = q.front();
    //             q.pop();
    //             if(node->left) q.push(node->left);
    //             else{
    //                 if(i!=0) ++count;
    //             }
    //             if(node->right) q.push(node->right);
    //             else{
    //                 if(i!=size-1) ++count;
    //             }
    //         }
    //         if(!q.empty()) count*= 2;
    //         ans = count; count = 0;
    //     }
    //     return ans;
    // }

      int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int first,last;
            for(int i=0;i<size;++i){
                int curr = q.front().second-mini;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = curr;
                if(i==size-1) last = curr;

                if(node->left) q.push({node->left,2*curr+1});
                if(node->right) q.push({node->right,2*curr+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }