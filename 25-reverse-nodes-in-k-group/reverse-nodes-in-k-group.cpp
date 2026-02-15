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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }

        int n = 0 ;

        ListNode*temp = head ;

        while(temp!=NULL && n<k){
            n++;
            temp = temp->next ;
        }

        if(n<k){
            return head ;
        }

        temp = head ;
        ListNode*prev = NULL ;
        ListNode*next = NULL ;
        n = 0;
        
        while(temp!=NULL && n<k){
            next = temp->next ;
            temp->next = prev ;
            prev = temp ;
            temp = next ;
            n++;
        }

        if(next!=NULL){
            head->next = reverseKGroup(next , k);
        }

        return prev ;
    }
};