
#include<iostream>
#include<utility>
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

vector<vector<int>> preInpost(TreeNode* root){
     vector<int> pre, in, post;
     if(!root){ 
        return {pre, in, post}; 
     }

    stack<pair<TreeNode*, int>> st;
    st.push({root,1});
   
    while(!st.empty()){
        auto &it = st.top();
        
        //part of pre
        // 1 to 2 
        // push the left side

        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            

            if(it.first->left) st.push({it.first->left,1});

            //part of in 
            //2 to 3
            // push the right side
//inorder
        }else if(it.second ==2){
                in.push_back(it.first->val);
                it.second++;
               
                if(it.first->right) st.push({it.first->right,1});
            }

            // dont push back again
            else {
                post.push_back(it.first->val);
                st.pop();
            }
                    
        
    }

return {pre, in ,post};
}

 int main(){
      TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      

    vector<vector<int>> soln = preInpost(root);
    for (const auto& t : soln) {
        cout << "{ ";
        for (int x : t) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }
return 0;
 }

 // here we pop at last, recursion style 
// we can also pop at start and push everytime 