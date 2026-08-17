#include<iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr; //No root  
    TreeNode* curr = root;
    TreeNode* prev = nullptr;
     while(curr && curr->val!= key){
            prev = curr;
            curr = key < curr->val ? curr->left : curr->right;
        }
        if(!curr) return root; //not found
       
       else if(!curr->left || !curr->right){
            TreeNode* child = curr->left?curr->left : curr->right;
            //root
            if(!prev){
                delete curr; return child;
            }
            if(prev->left==curr)prev->left = child;
            else prev->right = child;
            delete curr;
            return root;
        }
        else{
           TreeNode*temp = curr->right;
           TreeNode* prevTemp =curr;
           
           while(temp->left) {
            prevTemp = temp;
            temp = temp->left;
           }
           curr->val = temp->val;
           if(prevTemp->left==temp) prevTemp->left = temp->right;
           else prevTemp->right = temp->right;
           delete temp;
        }
     return root;
    }

//method 2
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr; //No root  
    TreeNode* curr = root;
    TreeNode* prev = nullptr;
     while(curr && curr->val!= key){
            prev = curr;
            curr = key < curr->val ? curr->left : curr->right;
        }
        if(!curr) return root; //not found
       
       else if(!curr->left || !curr->right){
            TreeNode* child = curr->left?curr->left : curr->right;
            //root
            if(!prev){
                delete curr; 
                return child;
            }
            if(prev->left==curr)prev->left = child;
            else prev->right = child;
            delete curr;
            return root;
        }
          TreeNode* rightSub = curr->right;
          TreeNode* leftSub = curr->left;
          //find leftmost in right subtree
          TreeNode* temp = rightSub;
            while(temp->left){
               temp = temp->left;
            }
            //attach left subtree there
            temp->left = leftSub;
            //Replacing curr with rightSub

            //C1 deleting root
            if(!prev){
                delete curr;
                return rightSub;
            }
            //C2 curr is left child
            if(prev->left == curr){
                prev->left = rightSub;
            }
            //C3 curr is right child
            else{
                prev->right = rightSub;
            }
            delete curr;        
            return root;
    }