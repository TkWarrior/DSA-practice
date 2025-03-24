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
       
       //Edge cases
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        //we will traverse the linked list and will count the no of nodes
       while(l1!=NULL ){
            count++;
            l1 = l1->next;
            
       }
        
        // if the number of nodes is equal to element's position which has to be deleted
        // it means it is pointed towards head of the linked list
        if(count==n){
            //we will Node pointer to the head->next
            ListNode* newHead = head->next;
            //then we will delete the head
            // delete head;
            // will return the new head
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
        //  delete deleteNode;
        }
       
        return head;
    }
};