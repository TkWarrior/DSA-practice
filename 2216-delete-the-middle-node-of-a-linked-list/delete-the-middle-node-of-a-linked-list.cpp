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
       ListNode* l1 = head;
       int count=0;
       //edge cases
       if(head==NULL || head->next==NULL){
            return NULL;
       }
    //    if(head!=NULL && head->next==NULL){
    //         return head;
    //    }
       while(l1!=NULL && l1->next!=NULL){
            count++;
            l1 = l1->next;
       }
       count++;
       int mid = count/2;
       l1 = head;
       for(int i = 0 ; i<mid-1 ; i++){
            l1 = l1->next;
       }
       l1->next = l1->next->next;
       return head;
    }
};