#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if(headA==nullptr && headB==nullptr) return nullptr;
    ListNode*t1 = headA;
    ListNode*t2 = headB;
  //  while(t1!=t2){
  //   t1 = t1->next;
  //   t2= t2->next;
  //   if(t1==t2) return t1;
  //   if(t1==nullptr) t1 = headB;
  //   if(t2== nullptr) t2 = headA;
  //  }
  while (t1 != t2) {
        t1 = (t1 == nullptr) ? headB : t1->next;
        t2 = (t2 == nullptr) ? headA : t2->next;
    }
   return t1;          
    }

    int main() {
    // -------- Create intersecting lists --------
    //
    // List A: 1 -> 2 -> 3
    //                     \
    //                      8 -> 9 -> 10
    //                     /
    // List B:       4 -> 5

    ListNode* common = new ListNode(8);
    common->next = new ListNode(9);
    common->next->next = new ListNode(10);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common;

    // Print List A
    cout << "List A: ";
    ListNode* temp = headA;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Print List B
    cout << "List B: ";
    temp = headB;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Find intersection
    ListNode* inter = getIntersectionNode(headA, headB);

    if (inter)
        cout << "Intersection at node with value: " << inter->val << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
