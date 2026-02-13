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
    ListNode* reverseLL(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head ;
        }
        ListNode*last = reverseLL(head->next);
        head->next->next = head ;
        head->next = NULL ;

        return last ; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = reverseLL(l1);
        ListNode* L2 = reverseLL(l2);

        ListNode* res = new ListNode(l1->val);
        int sum = 0 ;
        int carry = 0 ;

        while(L1!=NULL || L2!=NULL){

            if(L1!=NULL){
                sum += L1->val;
                L1 = L1->next ;
            }
           
            if(L2!=NULL){
                sum += L2->val;
                L2 = L2->next ;
            }

            res->val = sum%10 ; 
            carry = sum/10 ;
            ListNode* dummyNode = new ListNode(carry);
            dummyNode->next = res ;
            res = dummyNode ;
            sum = carry ;
        }

        if(carry==0){
            return res->next;
        }
        
        return res ;
    }
};