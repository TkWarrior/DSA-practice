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

    bool isValid(TreeNode*root , long long min_val , long long max_val){
        if(root==NULL){
            return true;
        }
        if(root->val >= max_val || root->val <= min_val) {
            return false;
        }

        return isValid(root->left , min_val , root->val ) && isValid(root->right , root->val , max_val);
    }
    
    bool isValidBST(TreeNode* root) {
        long long min_val = LONG_MIN;
        long long max_val = LONG_MAX;

        // for single node
        if(root!= NULL){
            if(root->left == NULL && root->right == NULL){
                return true;
            }
        }
        return isValid(root, min_val , max_val);
      
    }
};