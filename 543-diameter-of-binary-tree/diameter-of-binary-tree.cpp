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
    
    int height(TreeNode* node){
        if(node == NULL) return 0 ; 

        int left  = height(node->left);
        int right = height(node->right);

        return 1 + max(left , right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {

        if(root==NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int leftSubtreeDiameter = diameterOfBinaryTree(root->left);
        int rightSubtreeDiameter = diameterOfBinaryTree(root->right);

        return max(height(root->left) + height(root->right) , max(leftSubtreeDiameter , rightSubtreeDiameter));
       
    }
};