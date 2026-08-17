#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node*next;

    //constructor
    public:
    Node(int data1, Node *next1){
        data = data1;
        next = next1;

    }
};

int main(){
    vector <int> arr = {5,6,8,9};
    Node *y = new Node(arr[0], nullptr);
    cout << y << endl;
    cout << y->data;
    return 0;
}

