/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    else{
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if((left == 0 && right != 0) || (left != 0 && right == 0)){
            if(left > right){
                return left + 1;
            }else{
                return right + 1;
            }
        }
        
        if(left > right){
            return right + 1;
        }else{
            return left + 1;
        }
    }
}
