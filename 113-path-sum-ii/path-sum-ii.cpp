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

    vector<vector<int>>ans;
    vector<int>res;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum , int sum = 0 ) {
    
        if(root==NULL){
            return {};
        }

        sum += root->val;
        res.push_back(root->val);
         
        if(root->left==NULL && root->right==NULL){
            if(sum == targetSum){
                ans.push_back(res);
            }
        }

        pathSum(root->left , targetSum , sum);
        
        pathSum(root->right , targetSum , sum);

        res.pop_back();

        return ans;
    }
};