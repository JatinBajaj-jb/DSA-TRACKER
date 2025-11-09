// Approach 1 : Lis meothod +memo
class Solution {
private:
    bool check(string& s1,string& s2){

        if(s1.length()-s2.length()!=1) return false;
        int i=0,j=0;
        while(j<s2.length() && i<s1.length()){
            if(i<s1.length() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==s2.length();
    }
    int solve(vector<string>& words,int i,int p,int n,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int take=0;
        if( p==-1 || check(words[i],words[p])){
            take=1+solve(words,i+1,i,n,dp);
        }
        int ntake=solve(words,i+1,p,n,dp);
        return dp[i][p+1]=max(take,ntake);
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string& a,string& b){
            return a.length()<b.length();
        });
        vector<vector<int>> dp(n,vector<int>(n,1));
        return solve(words,0,-1,n,dp);
    }
};


// Approach 2 : I used bottom up approach 
class Solution {
private:
    bool check(string& s1,string& s2){
        if(s1.length()-s2.length()!=1) return false;
        int i=0,j=0;
        while(j<s2.length() && i<s1.length()){
            if(s1[i]== s2[j]) {
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& s1,string& s2){
            return s1.length()<s2.length();
        });
        int n=words.size();
        vector<int> t(n,1);
        int result=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])){
                    t[i]=max(t[i],t[j]+1);
                    result=max(result,t[i]);
                }
            }
        }
        return result;
    }
};
