// Approach 1: I tried the brute force approach 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(nums[j]<nums[i]){
                        result[i]++;
                    }
                }
            }
        }
        return result;
    }
};
// Approach 2 : I used unordered map 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int  n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            if(mp.find(temp[i])==mp.end()){
                mp[temp[i]]=i-0;
            }
        }
        for(int i=0;i<n;i++){
            nums[i]=mp[nums[i]];
        }
        return nums;
    }
};
