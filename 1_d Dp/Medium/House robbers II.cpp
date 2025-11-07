// Approach 1 : using memor
class Solution {
private:
    int solve(vector<int>& nums,int n,vector<int>& money,int st){
        if(st>n) return 0;
        if(money[st]!=-1) return money[st];
        return money[st]=max(solve(nums,n,money,st+1),solve(nums,n,money,st+2)+nums[st]);
    }
public:
    int rob(vector<int>& nums) {
    
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> money(n,-1);
        int a1=solve(nums,n-2,money,0);
        fill(money.begin(),money.end(),-1);
        int a2=solve(nums,n-1,money,1);
        return max(a1,a2);
    }
};
