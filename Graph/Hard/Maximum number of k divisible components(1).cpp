// Approach 1 : I used dfs to get the number of componenets
class Solution {
private:
    int dfs(int u,vector<vector<int>>& adj,vector<bool>&visited,int& component,vector<int>&values,int k){
        visited[u]=true;
        int curr=values[u];
    
        for(int& v:adj[u]){
            if(!visited[v]){
                curr+=dfs(v,adj,visited,component,values,k);
            }
        }
        if(curr%k==0){
            component++;
            return 0;
        }
        else{
            return curr%k;
        }
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int component=0;
        int sum=dfs(0,adj,visited,component,values,k);
    
        return component;
    }
};
