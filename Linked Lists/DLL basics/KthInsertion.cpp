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

Node* KthInsertion(Node*head,int k, int val){
    if(k<=0) return head;
    if(head==nullptr) return new Node(val); //empty
    if(k==1){
        Node*temp = new Node(val);
        head->back = temp;
        temp->next = head;
        return temp;
    }
    int cnt = 0;
    Node*temp = head;
    while(temp){
        ++cnt;
        //middle
        if(cnt==k-1 && temp->next!=nullptr){
            Node* bridge = new Node(val);
            Node*front = temp->next;
            bridge-> next = front;
            temp->next = bridge;
            front->back = bridge;
            bridge->back = temp;
            break;        
        }
        else if(cnt==k-1 && temp->next==nullptr){
            Node*end = new Node(val);
            temp->next = end;
            end->back = temp;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> boofi = {3,4,5,6,7,8,9};
    Node*head = convertArr2DLL(boofi);
    head = KthInsertion(head,4,77);
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}
