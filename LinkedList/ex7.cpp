//palindrome linked list
//leetcode 234
//url : https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
    ListNode* reverse(ListNode* slow){
        ListNode *p=nullptr,*n=nullptr;
        ListNode* c=slow;
        while(c!=nullptr){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        slow=p;
        return slow;
    }
    bool isPalindrome(ListNode* head) {
    ListNode* slow,*fast;
    slow=head;
    fast=head;
    while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;
    while(slow!=nullptr){
        if(head->val!=slow->val){
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;
    
    }
};