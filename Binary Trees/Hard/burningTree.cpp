#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void parentTrack(Node* root, unordered_map<Node*,Node*>& mpp, int target, Node* &Target){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->data== target) Target = curr;
        if(curr->left){
            mpp[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            mpp[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
// void dfsSearch(Node*root, int target, Node* &Target){
//     if(!root) return;
//     if(root->data == target) Target = root;
//     dfsSearch(root->left, target, Target);
//     dfsSearch(root->right,target,Target);
// }
int minTime(Node* root, int target) {
        if(!root) return 0;
        unordered_map <Node*, Node*> parent;
        Node*Target = nullptr;
        parentTrack(root,parent,target,Target); //Tracking the parents
        if(!Target) return 0;
        unordered_map<Node*, bool> visited;


        queue<Node*> q;
        q.push(Target); //starting from target
       visited[Target] = true;
        int time = 0;

        while(!q.empty()){
            int size = q.size();
            bool spread = false;
            for(int i = 0;i<size;++i){
                Node* curr = q.front(); q.pop();

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                    spread = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                     spread = true;
                }
                if(parent.count(curr) && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                     spread = true;
                }
            }
         if(spread) ++time;
        }
return time;
        
    }
