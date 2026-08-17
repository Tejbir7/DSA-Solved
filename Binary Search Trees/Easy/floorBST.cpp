 #include<iostream>
using namespace std;
class Node {
    public:
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
  };
  int floor(Node* root, int x) {
        int floor = -1;
        if(!root) return floor;
        while(root){
           if(root->data ==x ) return x;
           if(root->data <x){
            floor = root->data;
            root = root->right;
           }else root = root->left;
        }
        return floor;        
    }