//Linked List cycle 2
//leetcode 142
//url: https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
            ListNode* t=head;
            ListNode* s=head;
        if(head==nullptr){
            return nullptr;
        }
        else
        {
            while(t!=nullptr && t->next!=nullptr)
            {
                s=s->next;
                t=t->next->next;
                if(t==s){
                    s=head;
                    while(s!=t){
                        s=s->next;
                        t=t->next;
                    }
                    return s;
                }
            }
            return nullptr;
        }
    }
};