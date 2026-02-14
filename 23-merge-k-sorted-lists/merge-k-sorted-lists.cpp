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
    ListNode* mergeTwoList(ListNode*L1 , ListNode*L2){
        
        if(L1==NULL){
            return L2 ;
        }if(L2==NULL){
            return L1 ;
        }

        if(L1->val<=L2->val){
            L1->next = mergeTwoList(L1->next , L2);
            return L1 ;
        }else{
            L2->next = mergeTwoList(L1 , L2->next);
            return L2 ;
        }
    }
    ListNode* divideMerge(int s , int e , vector<ListNode*>& lists){
        // if there is only one node present
        if(s==e){
            return lists[s];
        }
        
        int mid = s + (e-s)/2 ;
        ListNode* L1 = divideMerge(s , mid , lists);
        ListNode* L2 = divideMerge(mid+1 , e , lists);

        return mergeTwoList(L1 , L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return {};
        int s = 0 , e = n-1 ;

        ListNode*res = divideMerge(s,e,lists);

        return res;
    }
};