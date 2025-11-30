// Approach 1 :I tried to get the target and find the subarray with its sum ==target 
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long result=LLONG_MAX;
        long long sum=accumulate(nums.begin(),nums.end(),0);
        long long target=sum%p;
        if(target==0) return 0;
        long long l=0,r=0;
        long long curr=0;
        while(r<n && l<n){
            curr+=nums[r];
            if(curr==target){
                result=min(result,r-l+1);
                curr=0;
                l=r+1;
            }
            while(curr>target){
                curr-=nums[l];
                l++;
            }
            r++;
        }
        if(result==n) return -1;
        return result==LLONG_MAX?-1 :result;
    }
};
// Approach 2 : I used prefix sum using hash map
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int result=INT_MAX;
        int sum=0;
        for(int &num:nums){
            sum=(sum+num)%p;
        }
        int target=sum;
        if(target==0) return 0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int curr=0;
        for(int j=0;j<nums.size();j++){
            curr=(curr+nums[j])%p;
            int remain=(curr-target+p)%p;
            if(mp.find(remain)!=mp.end()){
                result=min(result,j-mp[remain]);
            }
            mp[curr]=j;
     
        }
        if(result==nums.size() ||result==INT_MAX) return -1;
        return result;
    }
};
