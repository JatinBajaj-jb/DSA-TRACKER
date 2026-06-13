// Approach 1 : I tried to brute force my way through the problem and created a sorted array
class Solution {
private:
    void solve(TreeNode* root,vector<int>& output){
        if(!root) return;
        solve(root->left,output);
        output.push_back(root->val);
        solve(root->right,output);

        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> output;
        solve(root,output);
        return output[k-1];
    }
};
// Approach 2 :I made a linear space recursive solution 
class Solution {
private:
    void solve(TreeNode* root,int& k,int& result){
        if(!root) return;
        
        if(result!=-1) return;
        solve(root->left,k,result);
        k--;
        if(k==0){
            result=root->val;
            return;
        }
        solve(root->right,k,result);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result=-1;
        solve(root,k,result);
        return result;
        
    }
};
