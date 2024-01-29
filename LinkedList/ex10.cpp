//Intersection of Two Linked Lists

//leetcode 160
//url: https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1&&l2&&l1!=l2){
           l1=l1->next;
           l2=l2->next;
           if(l1==l2){
               return l2;
           }
           if(l1==nullptr)l1=headB;
           if(l2==nullptr)l2=headA;

        }
        return l2;
    }
};