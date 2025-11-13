// Approach 1: Used dfs 
  class Solution {
private:
    void dfs(int u,vector<vector<int>>&adj,vector<bool>& visited){
        visited[u]=true;
        for(auto& v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
        return;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>> adj(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(auto val:rooms[i]){
                adj[i].push_back(val);
            }
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                visited[i]=false;
            }
        }
        for(int i=1;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;       
    }
};    

// Approach 2 : I used optimized soltution for dfs
class Solution {
private:
    void dfs(vector<vector<int>>& rooms,int u,vector<int>& visited){
        visited[u]=1;
        for(auto& v:rooms[u]){
            if(visited[v]==0){
                dfs(rooms,v,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        dfs(rooms,0,visited);
        vector<int>t(n,1);
        return t==visited;
    }
};

// Approach 3 : I used bfs 
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        queue<int> pq;
        pq.push(0);
        visited[0]=1;
        while(!pq.empty()){
            int u=pq.front();
            pq.pop();
            for(auto v:rooms[u]){
                if(visited[v]==0){
                    pq.push(v);
                    visited[v]=1;
                }
            }

        }
        vector<int>t(n,1);
        return t==visited;
    }
};
