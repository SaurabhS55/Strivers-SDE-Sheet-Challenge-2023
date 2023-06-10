// Finding middle of linked list  , leetcode: 876
// url: https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
    int count(ListNode* h){
        int c=0;
        while(h){
            c+=1;
            h=h->next;
        }
        return c;
    }
    ListNode* middleNode(ListNode* head) {
        int c=count(head);
        ListNode* n=head;
        for(int i=0;i<c/2;++i){
            n=n->next;
        }
        return n;
        
        
    }
};