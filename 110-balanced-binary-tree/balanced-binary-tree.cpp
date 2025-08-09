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

    int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        return 1+max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        
        // if the height diff b/w left and right subtree is <=1 then it is a balanced bibary tree
        if(root==NULL){
            return true;
        }
        int leftHeight = 0 ;
        int rightHeight = 0 ;
        if(root->left!=NULL){
             leftHeight = height(root->left);
        }
        if(root->right!=NULL){
             rightHeight = height(root->right);
        }
      // we've to check balanced condition at every level of tree root , left subtree , and right subtree
        return abs(rightHeight-leftHeight)<=1 && isBalanced(root->left) &&   isBalanced(root->right);
    }
};