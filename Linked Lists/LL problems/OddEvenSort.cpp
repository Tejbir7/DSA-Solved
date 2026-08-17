#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//    ListNode* oddEvenList(ListNode* head) {
//     if(!head || !head->next) return head;
//     ListNode* odd = head;
//     ListNode* even = head->next;
//     ListNode*evenHead = even;
//     while(even && even->next){
//         odd->next = even->next;
//         odd= odd->next;

//         even->next = odd->next;
//         even = even ->next;
//     }
//     odd->next = evenHead;
//     return head;         
//     }
//or
 ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode*evenHead = even;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even ->next;
    }
    odd->next = evenHead;
    return head;         
    }

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main() {

    // Test case 1: [1,2,3,4,5]
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(3);
    ListNode* a4 = new ListNode(4);
    ListNode* a5 = new ListNode(5);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    cout << "Original list 1: ";
    printList(a1);

    a1 = oddEvenList(a1);

    cout << "After odd-even:  ";
    printList(a1);
    cout << endl;


    // Test case 2: [2,1,3,5,6,4,7]
    ListNode* b1 = new ListNode(2);
    ListNode* b2 = new ListNode(1);
    ListNode* b3 = new ListNode(3);
    ListNode* b4 = new ListNode(5);
    ListNode* b5 = new ListNode(6);
    ListNode* b6 = new ListNode(4);
    ListNode* b7 = new ListNode(7);

    b1->next = b2;
    b2->next = b3;
    b3->next = b4;
    b4->next = b5;
    b5->next = b6;
    b6->next = b7;

    cout << "Original list 2: ";
    printList(b1);

    b1 = oddEvenList(b1);

    cout << "After odd-even:  ";
    printList(b1);
    cout << endl;


    // Test case 3: single node
    ListNode* c1 = new ListNode(10);
    cout << "Original list 3: ";
    printList(c1);

    c1 = oddEvenList(c1);

    cout << "After odd-even:  ";
    printList(c1);
    cout << endl;


    // Test case 4: empty list
    ListNode* d = nullptr;
    cout << "Original list 4: empty" << endl;
    d = oddEvenList(d);
    cout << "After odd-even:  empty" << endl;

    return 0;
}
