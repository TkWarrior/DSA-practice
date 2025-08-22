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
   
    int findBottomLeftValue(TreeNode* root) {
      queue<TreeNode*>q ; 

      q.push(root);

     
      vector<vector<int>>res;

      while(!q.empty()){
         vector<int>level ; 
        int n = q.size();
        while(n--){
            TreeNode*temp = q.front();
            q.pop();

            if(temp->left!=NULL){
                q.push(temp->left);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
            }
             level.push_back(temp->val);
         }

        res.push_back(level);
      }

      int bottonLeft = res[res.size()-1][0];

      return bottonLeft;


    }
};