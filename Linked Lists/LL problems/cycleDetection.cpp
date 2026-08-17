
#include<unordered_map>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Not optimal
//   bool hasCycle(ListNode *head) {
//     ListNode*temp = head;
//     unordered_map <ListNode*,int> mpp;
//     while(temp){
//         if(mpp.find(temp)!=mpp.end()){
//             return true;
//         }
//         mpp[temp] = 1;
//         temp = temp ->next;
//     }
//     return false;        
//     }

    //tortoise hare

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // create loop
    fifth->next = third;

    if (hasCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // NOTE: not deleting nodes because list is cyclic
    return 0;
}
