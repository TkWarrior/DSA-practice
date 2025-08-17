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
    vector<string>ans;
    vector<string> binaryTreePaths(TreeNode* root , string res="") {
        
        if(root==NULL){
            return {};
        }

        res += to_string(root->val);
        
        if(root->left==NULL && root->right==NULL ){
            ans.push_back(res);
        }
        res.push_back('-');
        res.push_back('>');
        binaryTreePaths(root->left , res );
        binaryTreePaths(root->right , res );

        return ans;
    }
};