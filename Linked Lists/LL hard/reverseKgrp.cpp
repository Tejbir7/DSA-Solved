#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
pair<ListNode*, ListNode*> reverseK(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (k--) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // prev = new head
    // head = new tail
    return {prev, head};
}


 ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prevGroupTail = dummy;
    ListNode*start = head;
    ListNode*temp = head;
    
    int cnt = 0;
 
   while(temp){
    ++cnt;

    if(cnt==k){
        ListNode* nextGrpHead = temp->next;

        auto p = reverseK(start,k);
        ListNode* newHead = p.first;       
        ListNode* newtail = p.second;

        prevGroupTail->next = newHead;
        newtail->next = nextGrpHead;

        prevGroupTail = newtail;
        start = nextGrpHead;
        temp = nextGrpHead;
        cnt = 0;
    }else{
    temp = temp->next;
    }
   }     
   return dummy->next; 
    }

    int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;

    cout << "Original List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    head = reverseKGroup(head, k);

    cout << "After reversing in k-group (k = " << k << "): ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
