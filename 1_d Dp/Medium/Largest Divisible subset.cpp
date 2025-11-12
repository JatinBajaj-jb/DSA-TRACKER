// Approach 1 : I used dp 
class Solution {
private:
    void solve(vector<int>& nums,int i,vector<int>& result,vector<int>& temp,int prev){
        if(i>=nums.size()){
            if(temp.size()>result.size()){
                result=temp;
            }
            return;
        }
        if(prev==-1 || nums[i]%prev==0){
            temp.push_back(nums[i]);
            solve(nums,i+1,result,temp,nums[i]);
            temp.pop_back();
        }
        solve(nums,i+1,result,temp,prev);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        vector<int> temp;
        solve(nums,0,result,temp,-1);
        return result;
    }
};
// Approach 2 : I used bottom up approach 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        if(n==0) return result;
        if(n==1){
            result.push_back(nums[0]);
            return result;
        }
        sort(nums.begin(),nums.end());

        vector<int> pre_i(n,-1);
        vector<int> t(n,1);
        int last_c=0;
        int maxl=1; 

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        pre_i[i]=j;
                    }
                }
                if(t[i]>maxl){
                    maxl=t[i];
                    last_c=i;
                }
            }
        }
        while(last_c!=-1){
            result.push_back(nums[last_c]);
            last_c=pre_i[last_c];
        }
        return result;
    }
};
