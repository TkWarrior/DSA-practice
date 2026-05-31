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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0 ;
        ListNode*temp = head;
        if(temp->next==NULL){
            return NULL;
        }
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }

        int size = n/2;
        temp = head ;

        for(int i = 0 ; i<size-1 ; i++){
            temp = temp->next;
        }

        if(temp->next!=NULL){
            temp->next = temp->next->next;
        }
        
        return head;
    }
};