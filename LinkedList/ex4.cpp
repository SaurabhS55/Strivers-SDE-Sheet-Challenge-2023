//Remove Nth Node From End of List , leetcode: 19
// url:https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    int getSize(ListNode *head){
        int c=1;
        while(head->next!=nullptr){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1){
            return nullptr;
        }
        int size=getSize(head)-n;
        if(size==0){
            return head->next;
        }
        // cout<<size<<" ";
        ListNode *l=head;
        for(int i=0;i<size-1;i++){
            l=l->next;
        }
        l->next=l->next->next;
        return head;
    }
};