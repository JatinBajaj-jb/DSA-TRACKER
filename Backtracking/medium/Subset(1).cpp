// Approach : I used backtracking aka take and not take method 
class Solution {
private:
    void solve(vector<vector<int>>& result,vector<int>& nums,vector<int>& temp,int i){
        if(i>=nums.size()) return;
        temp.push_back(nums[i]);
        solve(result,nums,temp,i+1);
        result.push_back(temp);
        temp.pop_back();
        solve(result,nums,temp,i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        solve(result,nums,temp,0);
        return result;
    }
};
