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

  //brute force
//  ListNode* middleNode(ListNode* head) {
//         ListNode*temp = head;
//         int cnt = 0;
//         while(temp){
//             ++cnt;
//             temp = temp->next;
//         } 
//         cnt = (cnt/2)+1;
       
//         temp = head;
//         int k =0;
//         while(temp){
//             ++k;
//             if(k==cnt){
//                 break;
//             }
//             temp = temp->next;
//         }
//         return temp;
//     }

//Tortoise hare method (optimal)
 ListNode*MiddleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode*slow= head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast ->next->next;
    }
    return slow;        
    }

    int main() {
    // Creating a sample linked list: 
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Find the middle node
    ListNode* middleNode = MiddleNode(head);

    // Display the value of the middle node
    cout << "The middle node value is: " << middleNode->val << endl;

    return 0;
}
   