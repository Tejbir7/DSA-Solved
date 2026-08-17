#include<iostream>
#include <queue>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    ListNode dummy(0);
    ListNode* temp = &dummy;
    while(t1 && t2){
        if(t1->val<=t2->val){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        
        }else{
            temp->next = t2;
             temp = t2;
            t2= t2->next;           
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummy.next;
   }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* head = lists[0];
       for(int i =1;i<lists.size();i++){
        head = mergeTwoLists(head,lists[i]);
       }
       return head;        
    }

//priority queue
ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<pair<int,ListNode*>,
    vector<pair<int,ListNode*>>,
    greater<pair<int,ListNode*>>> pq;

    //priority_queue<T, container, comparator>
    //greater<pair<int, Node*>>  It turns the heap into a MIN-HEAP as Default PQ is max-heap.
    //greater<T> means: Element with smaller value has higher priority

    for(int i = 0; i <lists.size(); i++){
        if(lists[i]){
            pq.push({lists[i]->val, lists[i]});
        }
    }

    ListNode dummy(0);
    ListNode*temp = &dummy;

    while(!pq.empty()){
        auto it = pq.top(); //return the element with highest priority
        pq.pop();

        if(it.second->next) pq.push({it.second->next->val, it.second->next});

        temp->next = it.second;
        temp = temp->next;
    }
return dummy.next;
}

//divide and conquer approach
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return nullptr;

    int interval = 1;
    int n = lists.size();

    while(interval<n){
     
        for(int i = 0; i+interval<n ; i+= interval*2){
            lists[i] = mergeTwoLists(lists[i],lists[i+interval]);
        }
        interval*=2;
    }
    return lists[0];
}