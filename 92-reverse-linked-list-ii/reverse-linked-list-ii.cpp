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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //store the linked list elements in an array 
        // Brute force approah 
        vector<int>nums;
        ListNode*p = head;
        while(p!=NULL){
            nums.push_back(p->val);
            p = p->next;
        }
        p = head;
        for(int i=1 ; i<left ; i++){
            p=p->next;
        }
        int n = nums.size();
        for(int i = right-1 ; i>= left-1 ; i--){
            p->val = nums[i];
            p = p->next;
        }
        return head;
        

    }
    
};