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
    int pairSum(ListNode* head) {
       
       ListNode*slow = head;
       ListNode*fast = head ;
        // finding middle of the linked list
       while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next ;
       }

       ListNode*mid = slow;

        // reversing the linked list

        ListNode*prev = NULL ;
        ListNode*temp = NULL ;

        while(mid!=NULL){
            temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }

        // finding max sum

        int res = 0 ;
        ListNode*curr = head;

        while(prev!=NULL){
            res = max(res , curr->val + prev->val);
            prev = prev->next;
            curr = curr->next;
        }

        return res ;
    }
};