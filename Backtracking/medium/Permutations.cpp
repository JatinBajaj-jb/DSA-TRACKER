class Solution {
private:

    void solve(vector<int>&nums,vector<vector<int>>& res,int indx){
        if(indx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=indx;i<nums.size();i++){
            swap(nums[i],nums[indx]);
            solve(nums,res,indx+1);
            swap(nums[i],nums[indx]);
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int indx=0;
        solve(nums,res,indx);
        return res;
    }
};
