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
    ListNode* rotateRight(ListNode* head, int k) {
    int i = 0 ;
    //Brute force Time complexity O(n^2)
    //edge cases
    if(head==NULL || head->next == NULL){
        return head;
    }
    ListNode *first = head;
    int size = 1;
    while(first->next!=NULL){
        first = first->next;
        size++;
    }
    int rotate = k%size;
    if(rotate == 0){
        return head;
    }
    while(i<rotate){
        ListNode* l1 = head->next;
        ListNode* l2 = head;
        while(l1->next!=NULL ){
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->next = head;
        head = l1;
        l2->next = NULL;
        i++;
    }
    
        
    return head;;
    }
};