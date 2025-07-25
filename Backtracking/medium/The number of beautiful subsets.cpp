// Approach 1: I just used normal backtracking along with a additional function as per the question ;
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
// Approach 2: I just used a hash map to check whether element+k || element-k exist or not , (set cant be used as the array may contain duplicate elements )
class Solution {
private:
    void solve(vector<int>& nums,vector<int> &temp,int k,int &ans,int indx,unordered_map<int,int> &mp,int n){
        if(indx>=n){
            return;
        }
        for(int i=indx;i<n;i++){
            if(temp.empty() || (mp[nums[i]+k]==0 && mp[nums[i]-k]==0)){
                temp.push_back(nums[i]);
                mp[nums[i]]++;
                ans++;
                solve(nums,temp,k,ans,i+1,mp,n);
                mp[nums[i]]--;
                temp.pop_back();
            }
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) { 
        int ans=0;
        vector<int> temp;
        unordered_map<int,int> mp;
        solve(nums,temp,k,ans,0,mp,nums.size());
        return ans;
    }
};
