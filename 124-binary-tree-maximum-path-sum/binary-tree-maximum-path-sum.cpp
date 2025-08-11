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
    int findMaxSumPath(TreeNode* node ,int&maxi){
        if(node==NULL){
            return 0;
        }

        int left_sum = max(0,findMaxSumPath(node->left,maxi)); // at any time left sum become negative then return 0
        int right_sum = max(0, findMaxSumPath(node->right , maxi));// at any time right sum become negative then return 0
        maxi = max(maxi ,  left_sum+ right_sum + node->val);

        return max(left_sum,right_sum)+ node->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

         findMaxSumPath(root , maxi);
         return maxi ; 
        
    }
};