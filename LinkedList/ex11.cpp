//Linked List Cycle
//leetcode 141

//url: https://leetcode.com/problems/linked-list-cycle/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr){
            return false;
        }
        else{
            ListNode *n,*p;
            n=head;
            p=head;
            while(p!=nullptr && p->next!=nullptr){
                p=p->next->next;
                n=n->next;
                if(n==p){
                    return true;
                }

            }
            return false;
        }
       
    }
};