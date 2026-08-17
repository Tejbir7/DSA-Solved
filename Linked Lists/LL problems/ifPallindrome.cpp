#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  ListNode* reverseLL(ListNode*head){
    ListNode*prev = nullptr;
    ListNode* curr = head;
    while(curr){
        ListNode* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr= front;    
    }
    return prev;
  }

  bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode*slow = head;
    ListNode*fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode * right = reverseLL(slow->next);
    ListNode* left = head;
    while(right){
        if(left->val!=right->val) return false;
        left = left->next;
        right= right->next;
    }
    return true;            
    }

    //reverse the reversed LL to not destroy the original

    int main() {
    // ---------- Test case 1: Palindrome (odd length) ----------
    // 1 -> 2 -> 3 -> 2 -> 1
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(3);
    ListNode* a4 = new ListNode(2);
    ListNode* a5 = new ListNode(1);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    cout << "Test 1 (odd palindrome): "
         << (isPalindrome(a1) ? "Palindrome" : "Not Palindrome") << endl;

    // ---------- Test case 2: Palindrome (even length) ----------
    // 1 -> 2 -> 2 -> 1
    ListNode* b1 = new ListNode(1);
    ListNode* b2 = new ListNode(2);
    ListNode* b3 = new ListNode(2);
    ListNode* b4 = new ListNode(1);

    b1->next = b2;
    b2->next = b3;
    b3->next = b4;

    cout << "Test 2 (even palindrome): "
         << (isPalindrome(b1) ? "Palindrome" : "Not Palindrome") << endl;

    // ---------- Test case 3: Not a palindrome ----------
    // 1 -> 2 -> 3 -> 4
    ListNode* c1 = new ListNode(1);
    ListNode* c2 = new ListNode(2);
    ListNode* c3 = new ListNode(3);
    ListNode* c4 = new ListNode(4);

    c1->next = c2;
    c2->next = c3;
    c3->next = c4;

    cout << "Test 3 (not palindrome): "
         << (isPalindrome(c1) ? "Palindrome" : "Not Palindrome") << endl;

    // ---------- Test case 4: Single node ----------
    ListNode* d1 = new ListNode(7);

    cout << "Test 4 (single node): "
         << (isPalindrome(d1) ? "Palindrome" : "Not Palindrome") << endl;

    // ---------- Test case 5: Empty list ----------
    ListNode* e = nullptr;

    cout << "Test 5 (empty list): "
         << (isPalindrome(e) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
