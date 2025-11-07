class Solution {
private:  
    int solve(int n,vector<int>& mem){
        if(n<0)return 0;
        if(n==0)return 1;
        if(mem[n]!=-1)return mem[n];
        return mem[n]=solve(n-1,mem)+solve(n-2,mem);
    }
public:
    int climbStairs(int n) {
        vector<int> mem(n+1,-1);
        return solve(n,mem);
    }
};
