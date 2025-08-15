
class Solution {
private:
    void solve(TreeNode* root,int target,bool& result){
        if(root==NULL || result==true){
            return;
        }
        target-=root->val;
        if(target==0 && !root->left &&!root->right){
            result=true;
            return;
        }
        solve(root->left,target,result);
        solve(root->right,target,result);
        target+=root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL || targetSum==0){
            return false;
        }
        bool result=false;
        solve(root,targetSum,result);
        return result;
    }
};
