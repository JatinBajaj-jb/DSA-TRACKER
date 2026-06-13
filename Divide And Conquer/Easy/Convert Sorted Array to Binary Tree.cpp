// Approach 1 : I used recursive approach 
class Solution {
private:
    TreeNode* solve(vector<int>& nums,int left,int right){
        if(left>right) return nullptr;

        int mid=left+(right-left)/2;

        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=solve(nums,left,mid-1);
        curr->right=solve(nums,mid+1,right);

        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        TreeNode* root=solve(nums,left,right);
        return root;
    }
};
