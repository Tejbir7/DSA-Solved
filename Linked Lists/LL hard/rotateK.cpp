#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* rotateRight(ListNode* head, int k) {
    if(!head || k<=0) return head;

    int size =1;
    ListNode*tail = head;

    while(tail->next){
        tail = tail->next;
        ++size;
    }

    k = k%size;
if(k==0) return head;


ListNode* temp = head;
int count = 0;

while(temp){
    ++count;

    if(count==(size-k)){
        ListNode* newH = temp->next;

        tail->next = head;
        temp->next = nullptr;

        return newH;
    }
    temp = temp->next;
}
return head;        
    }