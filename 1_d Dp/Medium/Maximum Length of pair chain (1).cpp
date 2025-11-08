// Approach 1 : dp + memo
class Solution {
private:
    int solve(vector<vector<int>>& pairs,vector<vector<int>>& memo,int i,int p){
        if(i>=pairs.size()) return 0;
        if(memo[i][p+1]!=-1) return memo[i][p+1];

        int take=0;
        if(p==-1 || pairs[i][0]>pairs[p][1]){
            take=1+solve(pairs,memo,i+1,i);
        } 
        int ntake=solve(pairs,memo,i+1,p);
        return memo[i][p+1]=max(take,ntake);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<vector<int>> memo(n,vector<int>(n+1,-1));
        return solve(pairs,memo,0,-1);
    }
};
// Approach 2 : Bottom up approach 
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> t(n+1,1);
        int result=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    t[i]=max(t[i],t[j]+1);
                    result=max(result,t[i]);
                }
            }
        }
        return result;
    }
};
