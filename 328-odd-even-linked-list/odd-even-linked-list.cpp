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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        vector<int>arr;

        //Edge cases
        if(head==NULL || head->next ==NULL){
            return head;
        }
        //first we will store the add index linked list to the array it is the 1 - based indexing
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        // this is the condition when temp!=NULL but temp->next = NULL iss case mein fir hum array mein wo last element push kar denge
        if(temp){
            arr.push_back(temp->val);
        }
        //after that we will store the even index linked list to the array
        temp = head->next;
        while(temp!=NULL && temp->next!=NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp){
            arr.push_back(temp->val);
        }
        
        temp = head;
        for(int i = 0 ; i<arr.size() ; i++){
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};