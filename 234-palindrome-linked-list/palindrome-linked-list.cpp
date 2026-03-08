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
    bool isPalindrome(ListNode* head) {
        
        ListNode*fast = head;
        ListNode*slow = head ;

        if(head==NULL || head->next==NULL){
            return true;
        }

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode*curr = slow ; 
        ListNode*prev = NULL ;
        ListNode*temp = NULL ;
        
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev ;
            prev = curr ; 
            curr = temp ;
        }

        temp = head ;

        while(prev!=NULL && temp!=NULL){
            if(temp->val != prev->val){
                return false;
            }
            prev = prev->next;
            temp = temp->next;
        }

        return true;
        
    }
};