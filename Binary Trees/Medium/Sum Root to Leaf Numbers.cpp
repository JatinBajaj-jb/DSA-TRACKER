// Approach 1 : I used recursive approach to solve the problem 
class Solution {
private:
    void solve(TreeNode* root,int curr,int& sum){
        if(!root) return;
        
        if(!root->left && !root->right){
            sum+=curr*10+root->val;
            return;
        }
        solve(root->left,curr*10+root->val,sum);    
        solve(root->right,curr*10+root->val,sum);
    
        return;

    }
public:
    int sumNumbers(TreeNode* root) {
        int result=0;
        int curr=0;
        solve(root,curr,result);
        return result;
    }
};
