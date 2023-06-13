//  Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

//leetcode 237
//url : https://leetcode.com/problems/delete-node-in-a-linked-list/
class Solution {
public:
    void deleteNode(ListNode* node) {
        int d=node->next->val;
        node->val=d;
        node->next=node->next->next;
    }
};