#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  //Approach 1 unsafe
   vector<vector<int>> zigzagLevelOrderDQ(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);

        bool leftToright = true;

        while(!dq.empty()){
            int size = dq.size();
            vector<int> level;

           for(int i=0;i<size;++i){
            if(leftToright){
                TreeNode* node = dq.front();
                dq.pop_front();
                level.push_back(node->val);
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
               
            }else{
                TreeNode* node = dq.back();
                dq.pop_back(); 
                level.push_back(node->val);             
                if(node->right) dq.push_front(node->right); 
                if(node->left) dq.push_front(node->left);              
               
            }
           }
           ans.push_back(level);
          leftToright = !leftToright;
        }
return ans;
    }

    //Aproach 2 by queue
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToright = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i=0;i<size;++i){
            TreeNode* node = q.front();
            q.pop();

            int idx = leftToright? i: size-i-1;
            level[idx] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(level);
        leftToright = !leftToright;            
        }
return ans;
 }
        
    