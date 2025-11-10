class Solution {
private:
    void solve(TreeNode* root,int val,int depth,int curr){
        if(root==NULL || curr>=depth){
            return;
        }
        if(curr==depth-1){
            TreeNode* leftt=root->left;
            TreeNode* rightt=root->right;
            TreeNode* leftn=new TreeNode(val);
            TreeNode* rightn=new TreeNode(val);
            root->left=leftn;
            root->right=rightn;
            leftn->left=leftt;
            rightn->right=rightt;
        }
        solve(root->left,val,depth,curr+1);
        solve(root->right,val,depth,curr+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newn=new TreeNode(val);
            newn->left=root;
            return newn;
        }
        solve(root,val,depth,1);
        return root;
    }

};
