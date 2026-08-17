#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* getMiddle(ListNode*head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next&&fast->next->next){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

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

  ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;
    
    ListNode*middle = getMiddle(head);

    ListNode* left = head;
    ListNode* right = middle->next;
    middle->next = nullptr;

    ListNode* LeftH = sortList(left);
    ListNode* RightH = sortList(right);

return mergeTwoLists(LeftH,RightH);
    
        
    }
