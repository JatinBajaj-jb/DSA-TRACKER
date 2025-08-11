// Approach 1 : i just use the basic recursion method
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==q || root==p){
            return root;
        }
        TreeNode* leftn=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightn=lowestCommonAncestor(root->right,p,q);
        if(leftn!=NULL && rightn!=NULL){
            return root;
        }
        else if(!rightn){
            return leftn;
        }
        else{
            return rightn;
        }
    }
};
