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
   
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL){
            return NULL;
        }

        if(root->val == key){
            return help_delete(root);
        }

        TreeNode* temp = root;

        while(root!=NULL){
            
            if(root->val > key){
                if(root->left!=NULL && root->left->val == key){
                    root->left = help_delete(root->left);
                    break;
                 }else{
                    root = root->left;
                }
            }else{
                if(root->right!=NULL && root->right->val == key){
                    root->right = help_delete(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }     
        }

        return temp;   
    }  

    TreeNode* help_delete(TreeNode* root){
      
        if(root->left == NULL){
            return root->right;
        }

        else if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findRightLast(root->left);
        lastRight->right = rightChild;

        return root->left;

    } 

    TreeNode* findRightLast(TreeNode* root){
        if(root->right==NULL ){
            return root;
        }
        return findRightLast(root->right);
    }
};