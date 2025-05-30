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
    ListNode* reverseList(ListNode* head) {
       ListNode* temp = head;
       ListNode* tail = NULL;
       if(head==NULL || head->next == NULL){
            return head;
       }

       while(temp!=NULL ){
            ListNode* front = temp->next;
            temp->next = tail;
            tail = temp;
            temp = front;
            
       }
        head = tail;
       return head;

    }
};