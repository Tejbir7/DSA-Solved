#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;

struct Node{
    int key, val;
    Node* next, * back;

    Node(int key1, int val1, Node* next1 = nullptr, Node* back1 = nullptr){
        this->key = key1;
        this->val = val1;
        next = next1;
        back = back1;
    }
};

class LRUCache{
    private:
    unordered_map<int, Node*> mpp;
    Node* head ,* tail;
    int maxSize;
    int currSize = 0;

   void addFront(Node * first){
        Node * second = head->next;
        first->next = second;
        first->back = head;
        head->next = first;
        second->back = first;      
    }

    void removeNode(Node* delNode){
            delNode->back->next = delNode->next;
            delNode->next->back = delNode->back;        
    }

    public:
    LRUCache(int capacity){
        head =  new Node(-1,-1);
        tail =  new Node(-1,-1);
        head->next = tail;
        tail->back = head;
        maxSize = capacity;
        currSize = 0;
    }

    int get(int key){
       if(mpp.find(key) == mpp.end()) return -1;
       Node* first = mpp[key];
       removeNode(first);
       addFront(first);    
       return first->val;    
   }

    void put(int key, int value){
        if(maxSize == 0) return;
        if(mpp.find(key) != mpp.end()){
            Node* temp = mpp[key];
            temp ->val = value;
            removeNode(temp);
            addFront(temp);
            return;
        }
        if(currSize == maxSize){
            Node* leastUsed = tail->back;
           removeNode(leastUsed);
            mpp.erase(leastUsed->key);
            delete(leastUsed);           
            --currSize;
        }
        Node* first = new Node(key, value);
        mpp[key] = first;
       addFront(first);
        ++currSize;
    }

};