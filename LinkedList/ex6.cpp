//Add to numbers in linked list
//leetcode 2
//url : https://leetcode.com/problems/add-two-numbers/

// 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l4=new ListNode(0);
        ListNode* l3=l4;
        int c=0;
        while(l1!=nullptr || l2!=nullptr || c!=0){
            int x=l1?l1->val:0;
            int y=l2?l2->val:0;
            int d=c+x+y;
            c=d/10;
            l3->next=new ListNode(d%10);
            l3=l3->next;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
            
        }
    return l4->next;
    }
};