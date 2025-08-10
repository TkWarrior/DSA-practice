/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode*node1 ,TreeNode* node2){
        if(node1==NULL && node2==NULL){
            return true;
        }
        if(node1==NULL || node2==NULL){
            return false;
        }
        if(node1->val!=node2->val){
            return false;
        }
        if(node1->left == node2->right && node1->right == node2->left ){
            return true;
        }
       
        return isMirror(node1->left , node2->right) && isMirror(node1->right , node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        // if left subtree and right subtree is identicle then it is symmetrical otherwise not
        if(root==NULL){
            return true;
        }
       TreeNode* leftNode = root->left ; 
       TreeNode* rightNode = root->right;

       return isMirror(leftNode , rightNode);
    }
};