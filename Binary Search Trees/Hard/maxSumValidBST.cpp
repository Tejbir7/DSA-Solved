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
 class NodeValue{
    public:
    int maxNode, minNode, sum;
    bool isValid;

    NodeValue(int minNode, int maxNode, int sum, bool isValid){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->isValid = isValid;
        this->sum = sum;
    }

 };
 class Solution {
    private:
    // postOrder returns a NodeValue object, not pointer so use . instead ->
    int maxSum = 0;

    NodeValue postOrder(TreeNode* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0, true);

        auto left = postOrder(root->left);
        auto right = postOrder(root->right);

        if(left.isValid && right.isValid && left.maxNode < root->val && root->val < right.minNode){
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum,currSum);

            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), currSum, true);
        }
        //inValid BST
        return NodeValue(INT_MIN, INT_MAX,0,false);
    }
public:
    int maxSumBST(TreeNode* root) {
        postOrder(root);
        return maxSum;
        
    }
};