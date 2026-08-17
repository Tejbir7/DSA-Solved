#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    public:
    Node(int data1){
        data = data1;
        next= nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr ){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();++i){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
}

return head;
}


int main(){
    vector<int> arr = {5,6,7,8,9};
    Node* head = convertArr2LL(arr);
    cout<< head->data;
    return 0;


}