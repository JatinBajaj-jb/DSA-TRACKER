// Approach 1 : I used recursion 
class Solution {
private:
    int solve(string& word1,int i,string& word2,int j){
        if(j==word2.length()) return word1.length()-i;
        else if(i==word1.length()) return word2.length()-j;

        if(word1[i]==word2[j]) return solve(word1,i+1,word2,j+1);
        // Replace
        int r=1+solve(word1,i+1,word2,j+1);
        // delete
        int d=1+solve(word1,i+1,word2,j);
        // insert 
        int ins=1+solve(word1,i,word2,j+1);
        return min(r,min(d,ins));
    }
public:
    int minDistance(string word1, string word2) {
        int result=solve(word1,0,word2,0);
        return result;
    }
};
// Approach 2 : recursion +memo
class Solution {
private:
    int solve(string& word1,int i,string& word2,int j,vector<vector<int>>& dp){
        if(j==word2.length()) return word1.length()-i;
        else if(i==word1.length()) return word2.length()-j;

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=solve(word1,i+1,word2,j+1,dp);
        // Replace
        int r=1+solve(word1,i+1,word2,j+1,dp);
        // delete
        int d=1+solve(word1,i+1,word2,j,dp);
        // insert 
        int ins=1+solve(word1,i,word2,j+1,dp);
        return dp[i][j]=min(r,min(d,ins));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        int result=solve(word1,0,word2,0,dp);
        return result;
    }
};
// Approach 3 : Bottom up 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n==0) return m;
        else if(m==0) return n;
        vector<vector<int>> t(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            t[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            t[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else{
                    int re=1+t[i-1][j-1];
                    int de=1+t[i-1][j];
                    int ins=1+t[i][j-1];
                    t[i][j]=min(re,min(de,ins));
                }
            }
        }
        return t[n][m];
    }
};

