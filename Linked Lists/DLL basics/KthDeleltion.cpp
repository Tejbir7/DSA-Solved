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

Node* KthDeletion(Node*head, int k){
    if(head ==nullptr || k<=0) return head;
    Node*curr = head;
    int count = 0;
    if(k==1){
        Node*temp = head;
        head = head->next;
        if (head) head->back = nullptr;
        delete temp;
        return head;
    }
    while(curr){
        ++count;
        //middle
        if(count==k && curr->next != nullptr){
            Node*prev= curr->back;
            Node*front = curr->next;
            prev->next = front;
            front->back = prev;
            delete curr;
            break;
        }
        //tail
        else if(count==k && curr->next==nullptr){
            Node*prev = curr->back;
            prev->next = nullptr;
            delete curr;
            return head;
        }
        curr=curr->next;
    }
    return head;
}

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
    head = KthDeletion(head,3);
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;

}