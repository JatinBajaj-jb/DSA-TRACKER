// Approach : dp +memo
class Solution {
private:
    long long solve(vector<int>& nums,int i,bool IsEven,vector<vector<long long>>& memo){
        if(i>=nums.size()) return 0;
        if(memo[i][IsEven]!=-1) return memo[i][IsEven];

        long long taking=0;
        if(IsEven){
            taking=nums[i]+solve(nums,i+1,false,memo);
        }
        else{
            taking=solve(nums,i+1,true,memo)-nums[i];
        }
        long long  notTaking=solve(nums,i+1,IsEven,memo);
        return memo[i][IsEven]=max(taking,notTaking);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> memo(n+1,vector<long long>(2,-1));
        return solve(nums,0,true,memo);
    }
};
// Approach 3 :
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> memo(n+1,vector<long long>(2,0));
        for(int i=1;i<=n;i++){
            memo[i][0]=max(nums[i-1]+memo[i-1][1],memo[i-1][0]);
            memo[i][1]=max(memo[i-1][0]-nums[i-1],memo[i-1][1]);
        }
        return max(memo[n][1],memo[n][0]);
    }
};
// Approach 4 : I used constant space complexity 
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long add=0;
        long long sub=0;
        for(auto val:nums){
            add=max(add,sub+val);
            sub=max(sub,add-val);
        }
        return max(add,sub);
    }
};
