#include<iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* Copybetween(Node*head){
    Node* temp = head;
    while(temp){
        Node*copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
    return head;
}

Node* makeRandomConnections(Node*head){
    Node*temp = head;
    while(temp){
        Node*copyNode = temp->next;
        if(temp->random){
            copyNode->random = temp->random->next;
        }else{
            copyNode->random = nullptr;
        }
        temp= temp->next->next;
    }
    return head;
}

Node* finalizeStructure(Node*head){
    Node* dummyNode = new Node(0);
    Node*res = dummyNode;
    Node*temp = head;
    
    while(temp){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

 Node* copyRandomList(Node* head) {
    if(!head) return nullptr;

    Node* NewHead = Copybetween(head);
    NewHead = makeRandomConnections(NewHead);
    return finalizeStructure(NewHead);
        
    }