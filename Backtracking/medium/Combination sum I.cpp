// Approach 1: i just used the normal backtracking along with moving index +1 to remove duplicate
class Solution {
    int n;
private:
    void find(vector<int> &can,vector<vector<int>> &ans,vector<int> &temp,int target,int indx){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || indx>=n){
            return;
        }
        for(int i=indx;i<n;i++){
            temp.push_back(can[i]);
            find(can,ans,temp,target-can[i],indx);
            indx++;
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        find(candidates,ans,temp,target,0);
        return ans;
    }
};
// Approach 2 : I just used the basic take--or--skip recursion technique which was effective in removing duplicates 
class Solution {
    int n;
private:
    void find(vector<int> &can,vector<vector<int>> &ans,vector<int> &temp,int target,int indx){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || indx>=can.size()) return;

        temp.push_back(can[indx]);
        find(can,ans,temp,target-can[indx],indx);
        temp.pop_back();
        find(can,ans,temp,target,indx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        find(candidates,ans,temp,target,0);
        return ans;
    }
};
// Approach 3 : Honestly i tried to understand this approach , not the best for this question but it takes either a element 1 time or mutiple times or just skip the apporach 
class Solution {
set<vector<int>> st;
private:
    void find(vector<int> &can,vector<vector<int>> &ans,vector<int> &temp,int target,int indx){
        if(target==0){
            if(st.find(temp)==st.end()){
                ans.push_back(temp);
                st.insert(temp);
                return;
            }
        }
        if(target<0 || indx==can.size()) return;

        temp.push_back(can[indx]);
        find(can,ans,temp,target-can[indx],indx+1);
        find(can,ans,temp,target-can[indx],indx);
        temp.pop_back();
        find(can,ans,temp,target,indx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        find(candidates,ans,temp,target,0);
        return ans;
    }
};
