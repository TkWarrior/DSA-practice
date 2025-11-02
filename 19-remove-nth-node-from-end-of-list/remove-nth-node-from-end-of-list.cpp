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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head ; 
        int count = 0 ; 
        if(head == NULL ){
            return NULL ; 
        }
        while(temp!=NULL){
            count++ ;
            temp = temp->next ; 
        }

        temp = head ; 

        int rem = count-n ; 
        if(rem == 0){
            return head->next ; 
        }
        for(int i=0 ; i<rem-1 ; i++){
            temp = temp->next ; 
        }

        ListNode*delNode = temp->next ; 

        temp->next = delNode->next;

        return head ; 
    }
};  