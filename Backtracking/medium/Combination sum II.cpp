// Approach 1: I just used the basic backtracking problem but one thing i got to understand was how to skip duplicate paths , by sorting and if the number appears agains then to skip it 

class Solution {
private:
    void solve(vector<int>& can,vector<vector<int>>& result,vector<int>& curr,int target,int indx,int n){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0 || indx>n){
            return;
        }
        for(int i=indx;i<n;i++){
            if(i>indx && can[i]==can[i-1]){
                continue;
            }
            curr.push_back(can[i]);
            solve(can,result,curr,target-can[i],i+1,n);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,result,curr,target,0,n);
        return result;
    }
};
