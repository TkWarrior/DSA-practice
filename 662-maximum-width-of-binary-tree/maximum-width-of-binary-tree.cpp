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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0 ; 
        }

        queue<pair<TreeNode*,long long>>q;
        q.push({root , 0});
        long long ans = 0 ;
        long long curr_ind = 0;
      
       while(!q.empty()){
            long long size = q.size();
            long long min = q.front().second;
            long long left , right ; 
            for(long long i = 0 ; i<size; i++){
                curr_ind = q.front().second - min ; 
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) left = curr_ind ; 
                if(i==size-1) right = curr_ind; 
                if(node->left!=NULL){
                    q.push({node->left , curr_ind*2+1});
                }
                if(node->right!=NULL){
                    q.push({node->right , curr_ind*2+2});
                }
                      
            }
            ans = max(ans , right-left+1);
       }

       return ans ; 
    }
};