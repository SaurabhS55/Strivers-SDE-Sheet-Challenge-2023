//Reverse Linked List  leetcode: 206
// url: https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p=nullptr,*c=head,*n=nullptr;
        while(c!=nullptr){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        head=p;
        return head;
    }
};