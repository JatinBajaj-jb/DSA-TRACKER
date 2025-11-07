// Approach 1: I used memorization to solve the question 
class Solution {
private:
    int solve(int n,vector<int>& dp){
        if(n<=1)return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
// Approach 2 : I solved the question in sc (O(n));
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Approach 3: I used three variables to solve this in constant sc;
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        int a=0;
        int b=1;
        for(int i=1;i<n;i++){
            int c=a+b;
            a=b;
            b=c;
        }
        return b;     
    }
};

