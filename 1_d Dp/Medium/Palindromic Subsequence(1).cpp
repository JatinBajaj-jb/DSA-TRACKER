// Approach 1 : I used basic subsequence with palindrome using memo checker
class Solution {
private:
    bool isPalindrome(int i,int j,string& s,vector<vector<int>>& t){
        if(i>=j) return true;
        if(t[i][j]!=-1) return t[i][j];

        if(s[i]==s[j]){
            return t[i][j]=isPalindrome(i+1,j-1,s,t);
        }
        return t[i][j]=false;
    }
public:
    int countSubstrings(string s) {
        int n=s.length();
        int result=0;
        vector<vector<int>> t(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,t)) result++;
            }
        }
        return result;
        
    }
};
// Approach 2 : I used bottom up approach / isPalindrome blueprint
class Solution {
public:
    int countSubstrings(string s) {
        int result=0;
        int n=s.length();
        vector<vector<int>> t(n,vector<int>(n));
        for(int level=1;level<=n;level++){
            for(int i=0;i+level-1<n;i++){
                int j=level+i-1;

                if(i==j) t[i][j]=true;
                else if(i+1==j){
                    t[i][j]=(s[i]==s[j]);
                }
                else{
                    t[i][j]=(s[i]==s[j] &&t[i+1][j-1]);
                }
                if(t[i][j]) result++;
            }
        }
        return result;
    }
};
