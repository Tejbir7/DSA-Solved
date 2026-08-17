#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1= l1;
        ListNode* t2= l2;
        int carry = 0;
        ListNode*dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(t1 || t2 || carry){
            int sum = carry; //carry from prev digit
            if(t1) sum += t1->val;
            if(t2) sum += t2->val;

            carry = sum/10; //removes last digit
         curr->next= new ListNode(sum%10); //stores last digit
            curr = curr->next; 

            if(t1) t1 = t1->next; // till null
            if(t2) t2 = t2->next;      
        }
        return dummy->next;
}

int main() {
    // Number 1: 342 -> represented as 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Number 2: 465 -> represented as 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "Number 1 (reversed): ";
    ListNode* temp = l1;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Number 2 (reversed): ";
    temp = l2;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Sum (reversed): ";
    temp = result;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
