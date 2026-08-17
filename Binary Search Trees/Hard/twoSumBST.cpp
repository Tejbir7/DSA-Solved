#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  //Approach 1: basic
     void Inorder(TreeNode* root, vector<int> & inorder){
    if(root==nullptr) return;
    Inorder(root->left,inorder);
     inorder.push_back(root->val);
    Inorder(root->right,inorder);
  }
 bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        Inorder(root,inorder);
        int n = inorder.size();
       int left = 0, right = n-1;
       while(left<right){
        int sum = inorder[left]+ inorder[right];
        if(sum==k) return true;
        if(sum<k) ++left;
        else --right;
       }
       return false;   
    }    
 
       //Approach 2: Slight more optimal
  void inorder(TreeNode* root, int k, unordered_set<int> & set, bool &flag){
    if(root==nullptr) return;
    inorder(root->left,k,set,flag);
    if(set.count(k-root->val) ){
        flag = true;
        return;
    }    
    set.insert(root->val);
    inorder(root->right,k, set, flag);
  }
 bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        bool flag = false;
        inorder(root,k,set,flag);
        return flag;        
    }

    //Approach 3 Even cleaner and better
     bool solveDFS(TreeNode* root, int k, unordered_set<int> & set){
    if(root==nullptr) return false;
    if(solveDFS(root->left,k,set)) return true;
    if(set.count(k-root->val)){
        return true;
    }    
    set.insert(root->val);
    return solveDFS(root->right,k, set);
  }
 bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return solveDFS(root,k,set) ;        
    }

    //Approach 4: BSTiterator
    class BSTIterator{
        stack<TreeNode*> st;
        //reverse - true - before
        //reverse - false - next
        bool reverse = true;
        void pushAll(TreeNode* node){
            while(node){
                st.push(node);
                if(reverse){
                    node = node->right;
                }
                else node = node->left;

            }
        }
        public:
        BSTIterator(TreeNode* root, bool isReverse){
            reverse = isReverse;
            pushAll(root);
        }
        int next(){
            TreeNode* temp = st.top();
            st.pop();
            if(!reverse) pushAll(temp->right);
            else pushAll(temp->left);
            return temp->val;
        }
};

class Solution{
    public:
    bool findTarget(TreeNode* root, int k){
        if(!root ) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i= l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j<k) i = l.next();
            else j = r.next();

        }
        return false;
    }
};