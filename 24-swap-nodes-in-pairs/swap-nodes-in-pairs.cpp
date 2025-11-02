/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return head ; 
        }
        // dummy node

        ListNode* dummy = new ListNode(0);
        ListNode*curr = dummy ; 
       dummy->next = head ; 

        // at least 2 element in the heads to be present to swap the pairs
        while(curr->next!=NULL && curr->next->next!=NULL){
           ListNode*first = curr->next ; 
           ListNode*second = curr->next->next ; 

           // swapping
           first->next = second->next ; 
           second->next = first ; 
           curr->next = second;

           // move current node to first 2 steps so that it reaches the end
           curr = first ; 
        }

        return dummy->next ; 

    }
};