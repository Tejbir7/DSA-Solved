#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
    int cnt = 0;

    // {sum, number of nodes}
    array<int, 2> dfs(TreeNode* root) {

        if (!root->left && !root->right) {
            ++cnt;
            return {root->val, 1};
        }

        if (!root->left) {
            auto [sum, nodes] = dfs(root->right);

            int totalSum = sum + root->val;
            int totalNodes = nodes + 1;

            if (totalSum / totalNodes == root->val) {
                ++cnt;
            }

            return {totalSum, totalNodes};
        }

        if (!root->right) {
            auto [sum, nodes] = dfs(root->left);

            int totalSum = sum + root->val;
            int totalNodes = nodes + 1;

            if (totalSum / totalNodes == root->val) {
                ++cnt;
            }

            return {totalSum, totalNodes};
        }

        auto [leftSum, leftNodes] = dfs(root->left);
        auto [rightSum, rightNodes] = dfs(root->right);

        int totalSum = leftSum + rightSum + root->val;
        int totalNodes = leftNodes + rightNodes + 1;

        if (totalSum / totalNodes == root->val) {
            ++cnt;
        }

        return {totalSum, totalNodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};

//better
class Solution {
    int cnt = 0;

    array<int, 2> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftSum, leftNodes] = dfs(root->left);
        auto [rightSum, rightNodes] = dfs(root->right);

        int totalSum = leftSum + rightSum + root->val;
        int totalNodes = leftNodes + rightNodes + 1;

        if (totalSum / totalNodes == root->val) {
            ++cnt;
        }

        return {totalSum, totalNodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};