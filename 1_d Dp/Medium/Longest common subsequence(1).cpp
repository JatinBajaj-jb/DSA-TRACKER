// Approach 1 : I used bottom up approach 
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> t(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            t[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
        
    }
};
// Approach 2 : dp with memo
class Solution {
private:
    int solve(string text1,string text2,int i,int j,vector<vector<int>>& dp){
        if(i==text1.size() || j==text2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]){
            return dp[i][j]=1+solve(text1,text2,i+1,j+1,dp);
        }
        else{
            int take1=solve(text1,text2,i+1,j,dp);
            int take2=solve(text1,text2,i,j+1,dp);
            return dp[i][j]=max(take1,take2);
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        int result=solve(text1,text2,0,0,dp);
        return result;
    }
};

// Approach 3 : I used bottom up to get the result string 
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> t(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++){
            t[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            t[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        int i=n ,j=m;
        string result="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                result.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j]>t[i][j-1]){
                    i--;
                }
                else j--;
            }
        }
        return result;
    }
};

