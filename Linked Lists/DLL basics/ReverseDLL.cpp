#include<iostream>
#include<vector>
using namespace std;
struct Node{
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


Node* reverseDLL(Node*head){
    if (!head || !head->next) return head;
    Node* current = head;
    Node*prev = nullptr;
    while(current){
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
        }
    return prev->back;
}

int main(){
    vector<int> boofi = {3,4,5,6,7,8,9};
    Node*head = convertArr2DLL(boofi);
    head = reverseDLL(head);
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}