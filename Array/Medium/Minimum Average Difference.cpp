// Approach 1: i just used the standard approach of iteration , it has runtime error 
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int mind=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int first=0;
            int last=0;
            for(int j=0;j<nums.size();j++){
                if(j<i+1){
                    first+=nums[j];
                }
                else{
                    last+=nums[j];
                }
            }
            int leftavg=first/(i+1);
            int rightavg=i==nums.size()-1?0:last/(nums.size()-i-1);
            if(mind>abs(leftavg-rightavg)){
                ans=i;
                mind=abs(leftavg-rightavg);
            }
        }
    
        return ans;
    }
};
// Approach 2 : I just implemented basic optimization to improve the speed, so it is now O(n)
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        long long prev=LLONG_MAX;
        long long leftsum=0;
        long long rightsum=accumulate(nums.begin(),nums.end(),0LL);
        for(int i=0;i<n;i++){
            leftsum+=nums[i];
            rightsum-=nums[i];
            long long leftavg=(leftsum)/(i+1);
            long long rightavg=n-i==1?0:rightsum/(n-i-1);
            if(prev>abs(leftavg-rightavg)){
                prev=abs(leftavg-rightavg);
                ans=i;
            }
        }
        return ans;
    }
};

