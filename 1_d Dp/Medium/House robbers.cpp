// Approach 1 : used recursion + memo
class Solution {
private:
    int solve(vector<int>& nums,vector<int>& money,int n){
        if(n<0){
            return 0;
        }
        if(money[n]!=-1)return money[n];
        return money[n]=max(solve(nums,money,n-2)+nums[n],solve(nums,money,n-1));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size()
        vector<int> money(n+1,-1);
        return solve(nums,money,n-1);
    }
};
// Approach 2 : I used bottom up approach , note that the money vector is the max money at that iteration and not the money of that iteration 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==0)return 0;
        vector<int> money(n,-1);
        money[0]=nums[0];
        money[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            money[i]=max(money[i-2]+nums[i],money[i-1]);
        }
        return money[n-1];
        
    }
};
//Approach 3: I used three variable approach 
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        int a=nums[0];
        int b=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            int c=max(nums[i]+a,b);
            a=b;
            b=c;
        }
        return b;
    }
};

