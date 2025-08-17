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
   
    int sum = 0 ;
          
    bool hasPathSum(TreeNode* root, int targetSum , int sum=0) {
        if(root==NULL){
            return false;
        }
        
       sum += root->val;
       
        if(root->left == NULL && root->right == NULL){
            return sum==targetSum;
        }
        
       
        
        return hasPathSum(root->left , targetSum ,sum) || hasPathSum(root->right , targetSum ,sum);
        
       
    }
};