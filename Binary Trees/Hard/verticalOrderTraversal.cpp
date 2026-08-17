#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
vector<vector<int>> coordinates;

void dfs(TreeNode*root,int col, int row){
      if (!root) return;
    coordinates.push_back({col,row,root->val});
    if(root->left) dfs(root->left,col-1,row+1);
    if(root->right) dfs(root->right,col+1,row+1);
    return;
}
bool compare(const vector<int>&a , const vector<int>&b){
    if(a[0]!=b[0]) return a[0]<b[0];
    if(a[1]!=b[1]) return a[1]<b[1];
    return a[2]<b[2];
}

vector<vector<int>> setter(vector<vector<int>>&coordinates){
    sort(coordinates.begin(),coordinates.end(),compare);

    vector<vector<int>> ans;
    int prevCol = INT_MIN;
    for(auto &v: coordinates){
        if(v[0]!= prevCol){
            ans.push_back({});
            prevCol = v[0];
        }
        ans.back().push_back(v[2]);
    }
    return ans;
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
       
        if(!root) return {};
        coordinates.clear();
        dfs(root,0,0);
        
        return setter(coordinates);
        
    }
  