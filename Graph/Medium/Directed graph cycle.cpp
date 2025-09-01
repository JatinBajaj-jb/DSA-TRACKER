// Approach 1: I used DFS for this , we use another vector alongside visited that marks if the node has been visited in a recursion , 
class Solution {
 
  public:
    bool dfs(int u,vector<bool>& visited,vector<bool>& inrecursion,vector<vector<int>> &edges){
        visited[u]=true;
        inrecursion[u]=true;
        for(int v:edges[u]){
            if(!visited[v] && dfs(v,visited,inrecursion,edges)){
                return true;
            }
            else if(inrecursion[v]){
                return true;
            }
        }
        inrecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool> visited(V,false);
        vector<bool> inrecursion(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i,visited,inrecursion,edges)){
                return true;
            }
        }
        return false;
        
    }
};

// Approach 2 : I used Kahns algorithmn or topological sort in the graph if it didnt work then the graph is cyclic 
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> indegree(V,0);
        for(auto val:edges){
            for(int i:val){
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int countnode=0;
        while(!q.empty()){
            countnode++;
            int u=q.front();
            q.pop();
            for(int v:edges[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return countnode!=V;
    }
};

