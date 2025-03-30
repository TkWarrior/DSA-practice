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
        //brute force - time complexity = O(n)
        // space complexity = O(n)
        // vector<int>arr;
        // ListNode*l1 = head;
        // while(l1!=NULL){
        //     arr.push_back(l1->val);
        //     l1 = l1->next;
        // }
        // int n = arr.size();
        // for(int i = 0 ; i<n/2 ; i++){
        //     swap(arr[i],arr[n-i-1]);
        // }
        // l1 = head;
        // for(int i = 0 ; i<n ; i++){
        //     l1->val = arr[i];
        //     l1 = l1->next;
        // }
        // return head;

        // optimal soln - O(n) time complexity and O(1) space complexity
        ListNode* temp = head;
        
        ListNode* prev = NULL;
        while(temp!=NULL ){
            ListNode* front = temp->next;
            temp->next = prev;
            
            prev = temp;
            
            temp = front;
        }
        // head = current;
        return prev;
    }
};