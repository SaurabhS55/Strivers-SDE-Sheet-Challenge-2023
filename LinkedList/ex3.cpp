// Merge two sorted Linked Lists , leetcode :21
// url: https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		  ListNode* l=new ListNode(0);
          ListNode* h=l;
          while(list1 && list2){
              int val1=(list1!=nullptr)?list1->val:0;
              int val2=(list2!=nullptr)?list2->val:0;
              if(val1<val2){
                  l->next=list1;
                  list1=list1->next;
              }
              else{
                  l->next=list2;
                  list2=list2->next;
              }
              l=l->next;
          }
          if(list1){
              l->next=list1;
          }
          if(list2){
              l->next=list2;
          }
          return h->next;
    }
};