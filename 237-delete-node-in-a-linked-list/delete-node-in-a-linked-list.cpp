/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    void deleteNode(ListNode* node) {
        
       ListNode* nextNode = node->next;
       // copy the value from the nextNode val 
       node->val = nextNode->val;
       // and then change the links
       node->next = nextNode->next;

    }
};