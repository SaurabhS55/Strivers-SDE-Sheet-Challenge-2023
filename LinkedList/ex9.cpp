// Rotate List
// LeeCode: #61
// url: https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        int n=1;
        ListNode* t=head;
        while(t->next!=nullptr){
            n++;
            t=t->next;
        }
        t->next=head;
        int size=n-(k%n);
        for(int i=0;i<size;i++)
        {
            t=t->next;
        }
        head=t->next;
        t->next=nullptr;
        return head;
    }
};