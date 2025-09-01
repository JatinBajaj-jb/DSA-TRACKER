// Approach 1: Dfs
class Solution {
private:
    void dfs(int u,vector<vector<int>>& isconnected,vector<bool>& visited){
        visited[u]=true;
        for(int i=0;i<isconnected.size();i++){
            if(u==i){
                continue;
            }
            if(isconnected[u][i]==1){
                int v=i;
                if(!visited[v]){
                    dfs(v,isconnected,visited);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isconnected) {
        int N=isconnected.size();
        vector<bool> visited(N,false);
        int count=0;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,isconnected,visited);
                count++;
            }
        }    
        return count;
    }
};
