#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* headInsertion(Node* head,int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* TailInsertion(Node* head, int val){
    Node* temp = new Node(val);
     if (head == nullptr) {
        return temp;
    }
    Node* mover = head;
    while(mover->next!= nullptr){
        mover = mover->next;
    }
    mover->next = temp;
    return head;
}

Node* KthInsertion(Node*head,int val, int k){
    if(head==nullptr){
        if(k==1) {return new Node(val);
        }else{
            cout << "Invalid case!";
            return nullptr;
        }
    }
    if (k <= 0) return head; 
    if (k == 1) {
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    int cnt = 0;
    while(curr){
        ++cnt;
        if(cnt==k-1){
            Node*temp = curr->next;
            Node* bridge =new Node(val);
            curr->next = bridge;
            bridge->next = temp;
            break;
        }
        curr = curr->next;
}
return head;
}

Node* convertArr2LL(vector<int> &arr ){
    if(arr.empty()) return nullptr;
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
    vector<int> arr = {7,5,6,7,7,8,9,7,7};
    Node* head = convertArr2LL(arr);
   head= KthInsertion(head,4,2);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
