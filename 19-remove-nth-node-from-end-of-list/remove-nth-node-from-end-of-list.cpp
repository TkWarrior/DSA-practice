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
        ListNode* l1 = head;
        int count = 0;
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
       while(l1!=NULL ){
            count++;
            l1 = l1->next;
            
       }
        
        if(count==n){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
      
       int res = count-n;
       l1 = head;
       while(l1!=NULL ){
           res--;
           if(res==0){
                break;
           }
          
           l1 = l1->next;
        }
        ListNode* deleteNode = l1->next;
        if(deleteNode){
             
       
         l1->next = deleteNode->next;
         delete deleteNode;
        }
       
        return head;
    }
};