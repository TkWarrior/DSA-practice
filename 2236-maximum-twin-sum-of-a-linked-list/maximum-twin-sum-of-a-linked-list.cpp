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
        int n = 0 ;
        
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }

        int nums[n];

        temp = head;
        int i = 0 ;

        while(temp!=NULL && i<n){
            nums[i] = temp->val;
            temp = temp->next;
            i++;
        }
        
        for(int n : nums){
            cout<<n<<endl;
        }

        int maxi = nums[0] ;
        
        for(int i = 0 ; i<n/2 ; i++){
            maxi = max(maxi , nums[i]+nums[n-i-1]);
        }

        return maxi ;
    }
};