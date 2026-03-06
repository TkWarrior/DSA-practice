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
        int maxi = INT_MIN;

        ListNode*slow = head;
        ListNode*fast = head;

        while(fast!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode*prev = NULL;
        ListNode*curr = slow;

        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;   
            prev = curr;
            curr = temp;
        }

        ListNode*curr2 = head ; 

        while(curr2!=NULL && prev!=NULL){
            maxi = max(maxi , curr2->val + prev->val);
            curr2 = curr2->next;
            prev  = prev->next;
        }

        return maxi;
    }
};