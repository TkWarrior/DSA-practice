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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*>q;
        int curr_level = 1 ; 
        int max_level = INT_MIN ;// level with maximum sum
        vector<int>level;
        unordered_map<int , int>umap;
       
        q.push(root);
       
        int max_sum = INT_MIN;
       
        if(root==NULL){
            return 0;
        }

        while(!q.empty()){
        
           int size = q.size();
      
           int sum = 0 ;

           for(int i = 0 ; i<size ; i++){
                
                TreeNode* temp = q.front() ; 
                q.pop();

                sum += temp->val;

                if(temp->left!=NULL){
                    q.push(temp->left);   
                    
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                   
                }
           }

           if(sum > max_sum){
                max_sum = sum;
                max_level = curr_level;
           }
           
           curr_level++;
            
        }

        return max_level;
       
    }
};