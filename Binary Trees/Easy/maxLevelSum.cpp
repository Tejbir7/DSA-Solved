#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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

int maxLevelSum(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int level = 0;
    int maxLevel = 1;
    int maxSum = INT_MIN;

    while (!q.empty()) {
        int size = q.size();
        int sum = 0;
        ++level;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = level;
        }
    }

    return maxLevel;   
}
  int main(){
        TreeNode* root = new TreeNode(5);
        TreeNode* leftLeaf = new TreeNode(6);
        TreeNode*rightLeaf = new TreeNode(7);
        root->left = leftLeaf;
        root->right = rightLeaf;
      
      int maxLevel = maxLevelSum(root);
      cout << maxLevel;
      return 0;
    }