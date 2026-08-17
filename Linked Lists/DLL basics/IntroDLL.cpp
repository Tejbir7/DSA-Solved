#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node*back;

    Node(int val,Node* next1 = nullptr, Node* back1 = nullptr){
        data = val;
        next = next1;
        back = back1;
    }
};

Node* convertArr2DLL(vector<int>&arr){
      if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node*prev = head;
    for(int i=1;i<arr.size();++i){
          Node*temp = new Node(arr[i],nullptr,prev);
         prev->next = temp;
         prev = temp;
    }
    return head;
}

int main(){
    vector<int> boofi = {3,4,5,6,7,8,9};
    Node*head = convertArr2DLL(boofi);
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}