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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*>q ; 
        q.push(root) ; 
        vector<int>right ; 
        if(root==NULL){
            return right;
        }
        while(!q.empty()){
            int size = q.size();
            vector<int>level ; 
          
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->right!=NULL){
                    q.push(node->right);
                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                level.push_back(node->val);
            }
            // reverse(level.begin(),level.end());
            right.push_back(level[0]);
        }

        return right ; 
    }
};