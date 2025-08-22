/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

         if(root==NULL){
            return NULL;
         }
        // hum poora tree trverse kar lenge and whenever we find any value equal to node p or node q we'll return that node
         if(root == p || root == q){
            return root; // means hum upar wale node ko ye root return karenge
         }

         TreeNode* leftNode =  lowestCommonAncestor(root->left , p , q);

         TreeNode* rightNode =  lowestCommonAncestor(root->right , p , q);


         if(leftNode!=NULL && rightNode!=NULL){ // if both the leftNode and the rightNode is not null then return the root that will the lowest common ancestor
            return root ;
         }
        
        if(leftNode!=NULL){ // if leftNode != NULL and rightNode == NULL then return leftNode that will be LowestCommon Ancestor
            return leftNode ; 
        }


         return rightNode; // if rightNode !=NUll  and leftNode == NULL then return rightNode that will be the lowest common ancestor

    }   
};