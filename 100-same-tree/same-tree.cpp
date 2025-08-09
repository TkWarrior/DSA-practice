/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are NULL it means two trees are same if they both are empty

        if(p==NULL &&  q==NULL){
            return true ; 
        }
        // if any on them is NULL then it is false for p = [] and q = [1] and vice versa
        if(p==NULL || q==NULL){
            return false;
        }
        // if borh values are not the same
        if(p->val != q->val){
            return false;
        }

        return   isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};