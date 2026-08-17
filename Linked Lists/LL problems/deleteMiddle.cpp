#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

   ListNode* deleteMiddle(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return nullptr;

    ListNode*slow = head;
    ListNode* fast=  head;
    ListNode*prev = nullptr;
    while(fast!=nullptr && fast->next!=nullptr){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
        prev->next = slow->next;
        delete slow;
        return head;
    }

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    head = deleteMiddle(head);

    cout << "After deleting middle node: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}


        
    