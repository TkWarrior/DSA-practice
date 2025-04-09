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
        ListNode*l1 = head;
        vector<int>ans;

        if(l1 == NULL || l1->next == NULL){
            return head;
        }
        while(l1!=NULL){
            
            ans.push_back(l1->val);
            l1 = l1->next;
        }
        l1 = head;
        for(int i = ans.size()-1 ; i>=0 ; i--){
           
            l1->val = ans[i];
            l1 = l1->next;
            
        }
        return head;
    }
};