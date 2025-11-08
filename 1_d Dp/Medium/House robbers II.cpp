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
// Approach 2 : I used constant space time approach 
class Solution {
private:
    int solve(vector<int>& nums,int st,int end){
        int len=end-st+1;
        if(len==1) return nums[st];
        int a=nums[st];
        int b=max(nums[st],nums[st+1]);
        for(int i=st+2;i<=end;i++){
            int c=max(nums[i]+a,b);
            a=b;
            b=c;
        }
        return b;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int l1=solve(nums,1,n-1);
        int l2=solve(nums,0,n-2);
        return max(l1,l2);
    }
};
// Approach 3 : I used memo
class Solution {
private:
    int solve(vector<int>& nums,int st,int end,vector<int>& money){
        if(st>end) return 0;
        if(money[st]!=-1) return money[st];

        return money[st]=max(nums[st]+solve(nums,st+2,end,money),solve(nums,st+1,end,money));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        vector<int> money(n,-1);
        int l1=solve(nums,0,n-2,money);
        
        fill(money.begin(),money.end(),-1);
        int l2=solve(nums,1,n-1,money);

        return max(l1,l2);
    }
};
