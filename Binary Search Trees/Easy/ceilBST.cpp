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
 int findCeil(Node* root, int x) {
        if(!root ) return -1;
        int last = -1;
        while(root && (root->data) !=x){
            if(root->data> x) last = root->data;
            root = x< root->data ? root->left : root->right;
        }
        if(root) return root->data;
       return last;
    }
    //Best Approach
    int findCeil(Node* root, int x) {
    int ceil = -1;
    while(root) {
        if(root->data == x) return x;
        if(root->data > x) {
            ceil = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}
