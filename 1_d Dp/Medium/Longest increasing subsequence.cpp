// Approach 1 :
class Solution {
private:
    int solve(vector<int>& nums,vector<vector<int>>& memo,int i,int p){
        if(i>=nums.size()) return 0;
        if(memo[i][p+1]!=-1) return memo[i][p+1];
        int take=0;
        if(p==-1 || nums[p]<nums[i]){
            take=1+solve(nums,memo,i+1,i);
        }
        int ntake=solve(nums,memo,i+1,p);
        return memo[i][p+1]=max(take,ntake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return solve(nums,memo,0,-1);
    }
};
// Approach 2 : I used bottom up approach ;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n,1);
        int result=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    memo[i]=max(memo[i],memo[j]+1);
                    result=max(memo[i],result);
                }
            }
        }
        return result;
    }
};
// Approach 3 : I used patience sorting approach 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted;
        for(int i=0;i<n;i++){
            int elem=nums[i];
            auto it=lower_bound(sorted.begin(),sorted.end(),elem);
            if(it==sorted.end()){
                sorted.push_back(elem);
            }
            else{
                *it=elem;
            }
        }
        return sorted.size();
    }
};
