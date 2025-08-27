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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        if(root == NULL){
            return -1;
        }

        vector<long long>res;

        queue<TreeNode*>q ; 

        q.push(root);

        long long sum = 0 ;
        
        while(!q.empty()){

            long long size = q.size();
            sum = 0 ;
            for(long long i = 0 ;  i < size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            } 

            res.push_back(sum);  
        }

        sort(res.begin() , res.end());

        long long n = res.size();

        if(n-k<0){
            return -1 ; 
        }
        return res[n-k];
    }
};