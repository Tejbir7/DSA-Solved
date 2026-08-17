#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;
struct Node{
    int key, val;
    int cnt; //Tells of which freq this guy is of
    Node* next;
    Node* prev;

    Node(int key1, int val1, Node* next1 = nullptr, Node* prev1 = nullptr){
        key = key1; val = val1;
        next = next1;
        prev = prev1;
        cnt = 1;
    }
};
struct List{
    int size;
    Node* head, *tail;
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head ->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node * first){
        Node * second = head->next;
        first->next = second;
        first->prev = head;
        head->next = first;
        second->prev = first;      
        ++size;
    }

    void removeNode(Node* delNode){
            delNode->prev->next = delNode->next;
            delNode->next->prev = delNode->prev;
            --size;
        
    }

};
class LFUCache {
    private:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSize, currSize, minFreq;

    void updateFreqList(Node* node){
        int currFreq = node->cnt; 
        freqListMap[currFreq]->removeNode(node); // removed from prevList
        if(currFreq == minFreq && freqListMap[currFreq]->size == 0) ++minFreq; //update minFreq if necessary

        node->cnt++; 
        int newFreq = node->cnt;

        if(freqListMap.find(newFreq) == freqListMap.end()){  //Creating new list if needed
            freqListMap[newFreq] = new List();
        }

        freqListMap[newFreq]->addFront(node);  //moving to front as recently used
        }


public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0, currSize = 0;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node * node = keyNode[key];
            int val = node->val;
            updateFreqList(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
            return;
        }
        if(currSize == maxSize){
            List* LowestfreqList = freqListMap[minFreq];
            Node* lruNode = LowestfreqList->tail->prev;
            LowestfreqList->removeNode(lruNode);
            keyNode.erase(lruNode->key);
            delete(lruNode);
            --currSize;
        }
        Node* node = new Node(key, value);
        minFreq = 1;
        if(freqListMap.find(minFreq) == freqListMap.end()) {
            freqListMap[minFreq] = new List();
        }
        freqListMap[minFreq]->addFront(node);
        keyNode[key] = node;
        currSize++;
        return;
    }
};
