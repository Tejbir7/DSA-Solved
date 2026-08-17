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

    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode*prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode*front= curr->next;
            curr->next = prev ;
            prev = curr;
            curr = front;

        }
        return prev;          
    }

    ListNode* convertArr2LL(vector<int> &arr ){
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i=1;i<arr.size();++i){
    ListNode* temp = new ListNode(arr[i]);
    mover->next = temp;
    mover = temp;
}
return head;
}


int main(){
    vector<int> arr = {7,5,6,7,7,8,9,7,7};
    ListNode* head = convertArr2LL(arr);
    head= reverseList(head);
    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
