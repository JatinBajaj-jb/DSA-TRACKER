class Solution {
int n;
private:
    bool find(vector<int> &temp,int element,int target){
        for(int j=0;j<temp.size();j++){
            if(temp[j]-element==target || element-temp[j]==target){
                return false;
            }
        }
        return true;
    }
    void solve(vector<int>& nums,vector<int> &temp,int k,int &ans,int indx){
        if(indx>n){
            return;
        }
        if(!temp.empty()){
            ans++;
        }
        for(int i=indx;i<n;i++){
            if(temp.empty() || find(temp,nums[i],k)){
                temp.push_back(nums[i]);
                solve(nums,temp,k,ans,i+1);
                temp.pop_back();
            }
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int ans=0;
        vector<int> temp;
        solve(nums,temp,k,ans,0);
        return ans;
    }
};