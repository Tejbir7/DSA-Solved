#include<iostream>
#include<unordered_map>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 // Not optimal
// ListNode *detectCycle(ListNode *head) {
//     ListNode*temp = head;
//     unordered_map <ListNode*,int> mpp;
//     while(temp){
//         if(mpp.find(temp)!=mpp.end()){
//             return temp;
//         }
//         mpp[temp]=1;
//         temp = temp->next;
//     }
//     return nullptr;        
//     }

//Floyd method
 ListNode *detectCycle(ListNode *head) {
    if(!head) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow= slow->next;
                fast = fast ->next;
            } return fast;
        }
    }
    return nullptr;        
    }
int main() {
    // -------- Case 1: List WITH a cycle --------
    //
    // 1 -> 2 -> 3 -> 4 -> 5
    //           ^         |
    //           |_________|
    // Cycle starts at node with value 3

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    ListNode* cycleNode = detectCycle(head);

    if (cycleNode)
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    else
        cout << "No cycle detected" << endl;

    // -------- Case 2: List WITHOUT a cycle --------
    //
    // 10 -> 20 -> 30 -> 40

    ListNode* head2 = new ListNode(10);
    head2->next = new ListNode(20);
    head2->next->next = new ListNode(30);
    head2->next->next->next = new ListNode(40);

    ListNode* cycleNode2 = detectCycle(head2);

    if (cycleNode2)
        cout << "Cycle detected at node with value: " << cycleNode2->val << endl;
    else
        cout << "No cycle detected in second list" << endl;

    return 0;
}

