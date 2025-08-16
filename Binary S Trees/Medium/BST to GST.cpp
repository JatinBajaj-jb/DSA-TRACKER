// Approach : I just used basic recursion 
class Solution {
int netsum=0;
public:
    TreeNode* bstToGst(TreeNode* root){
        if(!root){
            return NULL;
        }
        root->right=bstToGst(root->right);
        netsum+=root->val;
        root->val=netsum;
        root->left=bstToGst(root->left);
        return root;
    }
};
