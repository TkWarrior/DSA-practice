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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        // Initializing the queueu to store the nodes
        queue<TreeNode*>q;
        q.push(root);
        if(root == NULL){
            return ans;
        }
        while(!q.empty()){
            int size = q.size();
            vector<int>level ; 
            for(int i = 0 ; i<size ; i++){
                TreeNode* node = q.front() ; 
                q.pop();
                // if left side of the node of a tree exist then push that into the queue
                if(node->left!=NULL) {
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                // means har level ke tree ke element ko hum add karte ja rahe hai level array mein
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};