#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<queue>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
   vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
           Node* node= it.first;
           int line = it.second;
            q.pop();
            if(mpp.find(line)==mpp.end()) mpp[line]= node->data;

            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
    
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }