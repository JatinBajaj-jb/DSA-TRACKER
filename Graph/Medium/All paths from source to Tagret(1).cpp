// Approach dfs 
class Solution {
private:
    void solve(vector<vector<int>>& graph,int u,int target,vector<vector<int>>& result,vector<int>& temp){
        temp.push_back(u);
        if(u==target){
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        for(auto& v:graph[u]){
            solve(graph,v,target,result,temp);
        }
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> result;
        vector<int> temp;
        solve(graph,0,n-1,result,temp);
        return result;
    }
};
