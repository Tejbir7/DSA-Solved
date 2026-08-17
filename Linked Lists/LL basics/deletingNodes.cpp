#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* headDeletor(Node* head){
    if(head==nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp; // free(temp) for malloc;
    return head;
}

Node* tailDeletor(Node*head){
    if(head== nullptr|| head->next == nullptr) return nullptr;
    Node*temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* KthDeleter(Node*head, int k){
    if(head==nullptr || k<=0) return head;
    Node* temp = head;
    if(k==1){
        head = head->next;
        delete temp; 
        return head; 
    }

    int count = 0;
    Node*previous = nullptr;
    while(temp){
         ++count;
        if(count==k){
            previous->next= temp->next;
            delete temp;
            break;
        }
        previous= temp;
        temp=temp->next;

    }
    return head;
}

Node* ValueDeleter(Node*head, int value){
    if(head==nullptr) return nullptr;
    Node*temp = head;
     if(head->data==value){
        head=head->next;
        delete temp;
        return head;        
    }
    Node*previous = nullptr;
    while(temp){
        if(temp->data==value){
            previous->next = temp->next;
            delete temp;
            break;
        }
        previous = temp;
        temp = temp->next;
    }
return head;
}

Node* AbsoluteValueDeleter(Node*head, int value){
  
    while(head != nullptr && head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if(head==nullptr) return nullptr;

    Node*previous = head;
    Node*temp2= head->next;
    while(temp2){
        if(temp2->data==value){
            previous->next = temp2->next;
            delete temp2;
            temp2 = previous->next;
        }else{
        previous = temp2;
        temp2 = temp2->next;
    }}
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
   head= AbsoluteValueDeleter(head,7);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}