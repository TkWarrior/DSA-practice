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
        if(head==NULL){
            return head;
        }

        ListNode*temp = head ;

        int c = 0 ;

        while(temp!=NULL){
            c++;
            temp = temp->next ; 
        }
        int pos = c-n;

        if(pos==0){
            return head->next ;
        }

        temp = head;

        for(int i = 0 ; i<pos-1 ; i++){
            temp = temp->next;
        }
        
        ListNode*delNode = temp->next;
        temp->next = delNode->next ; 
        delNode->next = NULL ;

        return head ; 
    }
};  