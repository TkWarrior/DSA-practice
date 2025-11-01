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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
     
        unordered_map<int , int>umap ;

        for(int i = 0 ; i<nums.size() ;i++){
            umap[nums[i]]++;
        } 

        while(head!=NULL && umap.find(head->val)!=umap.end()){
            ListNode*curr = head ; 
            head = head->next ;
        }

        ListNode*temp = head ; 

        while(temp!=NULL && temp->next!=NULL){
            if(umap.find(temp->next->val)!=umap.end()){
                ListNode* curr = temp->next ; 
                temp->next = temp->next->next ;
            }else{
                temp = temp->next ; 
            }
        }

        return head;
    }
};