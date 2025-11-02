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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0 ;

        ListNode* temp = head ; 

        while(temp!=NULL){
            count++ ; 
            temp =temp->next ; 
        }
        temp = head;
        ListNode*l1 = NULL;
        ListNode*l2 = NULL ; 
        for(int i = 1 ; i<count+1 ; i++){
            if(i==k){
                l1 = temp ; 
            }if(i==count-k+1){
                l2 = temp ;
            }
            temp = temp->next ; 
        }
        swap(l1->val , l2->val);

        return head;
    }
};