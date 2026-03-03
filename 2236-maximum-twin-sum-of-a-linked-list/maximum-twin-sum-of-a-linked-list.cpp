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
        
        ListNode*temp = head ;
        ListNode*fast = head ;
        ListNode*slow = head ;
        
        while(fast!=NULL ){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode*mid = slow ;
        ListNode* prev = NULL;
    
        while(mid!=NULL){
            ListNode*temp = mid->next;
            mid->next = prev ;
            prev = mid ;
            mid = temp ;
        }

        temp = head ;
        int maxi = INT_MIN ;

        while(temp!=NULL && prev!=NULL){
            maxi = max(maxi , temp->val + prev->val);
            temp = temp->next;
            prev = prev->next ;
        }

        return maxi ;
    }
};