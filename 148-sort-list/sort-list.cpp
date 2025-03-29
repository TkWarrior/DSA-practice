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
    ListNode* findMid(ListNode*head){
       ListNode*fast = head->next;
       ListNode*slow = head;
       while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
       }
       return slow;
    }
    ListNode* mergetwoSortedList(ListNode*l1,ListNode*l2 ){
        ListNode*third = NULL;
        ListNode*last;
        if(l1->val <= l2->val){
            third = last = l1;
            l1 = l1->next;
            last->next = NULL;
        }
        else{
            third = last = l2;
            l2 = l2->next;
            last->next = NULL;
        }
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                last->next = l1;
                last = l1;
                l1 = l1->next;
                last->next = NULL;
            }
            else{
                last->next = l2;
                last = l2;
                l2 = l2->next;
                last->next = NULL;
            }
        }
        if(l1!=NULL){
            last->next = l1;
        }
        if(l2!=NULL){
            last->next = l2;
        }
        return third;
    }

    ListNode* sortList(ListNode* head) {
        //Optimal approach 
       
       if(head==NULL || head->next==NULL){
            return head;
       }
       ListNode*middle = findMid(head);
       
       ListNode*rightHead  = middle->next;
       middle->next = NULL;
       ListNode*leftHead = head;
       leftHead = sortList(leftHead);
       rightHead = sortList(rightHead);

       return mergetwoSortedList(leftHead,rightHead);
    }
};