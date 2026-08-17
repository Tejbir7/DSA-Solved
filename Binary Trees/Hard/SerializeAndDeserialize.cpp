#include<iostream>
#include<vector>
#include<string>


using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  void dfsPre(TreeNode* root, string &s){
    if(!root){
        s.append("#,");
        return;
    }
    s.append(to_string(root->val));
    s.push_back(',');
    dfsPre(root->left, s);
    dfsPre(root->right, s);
  }
  TreeNode* dfsBuild(vector<string>&nodes, int &i){
    if(nodes[i] == "#"){
        ++i;
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(nodes[i++]));
    root->left = dfsBuild(nodes,i);
    root->right = dfsBuild(nodes,i);
    return root;
}
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string pre = "";
        dfsPre(root, pre);
        return pre;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size()) return nullptr;

        vector<string>nodes;
        string temp;

        for(char c: data){
            if(c==','){
                nodes.push_back(temp);
                temp.clear();
            }
            else temp.push_back(c);
        }
        int i = 0;
        return dfsBuild(nodes,i);

    }
   