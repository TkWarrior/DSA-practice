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
    int kthSmallest(TreeNode* root, int k) {
        
        if(root ==NULL){
            return 0;
        }

        queue<TreeNode*>q;
        q.push(root);
        vector<int>res ; 
        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i<size ; i++){
                TreeNode* temp = q.front();
                res.push_back(temp->val);
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }

        }
        sort(res.begin(),res.end());

        return res[k-1];
    }
};