// Attempt : I tried to build the graph first and then detect a cycle in the undirected graph using dfs , 
class Solution {
private:
    pair<int,int> dfs(int i,vector<vector<int>>& adj,vector<bool>& visited,int parent){
        visited[i]=true;
        for(int& i1:adj[i]){
            if(!visited[i1]){
                dfs(i1,adj,visited,i);
            }
            else if(i1!=parent){
                return {i,i1};
            }
        }
        return {-1,-1};
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n+1,false);
        
        pair<int,int>node=dfs(1,adj,visited,-1);
        vector<int> result;
        result.push_back(node.first);
        result.push_back(node.second);
        return result;            

    }
};
// Approach 1: I got to understand that the problem was about solving the graph by checking if a connection already exist ,if not then add it to the graph ,aka we 
//  were building and checking the graph at the same point 
class Solution {
private:
    bool isReachable(int u,int target,vector<vector<int>>& adj,vector<bool>& visited){
        visited[u]=true;
        for(int& v:adj[u]){
            if(v==target) return true;
            else if(!visited[v] && isReachable(v,target,adj,visited)){
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> result;
        vector<vector<int>> adj(n+1); 
        vector<bool> visited(n+1,false);   
        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];
            if(isReachable(u,v,adj,visited)){
                result.push_back(u);
                result.push_back(v);
                return result;
            }
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            fill(visited.begin(),visited.end(),false);
        }   
        return result;
    }
};

// Approach 2 : I used the same concept but with dsu
class Solution {
private:
    int find(int i,vector<int>& parent){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i],parent);
    }
    void uniont(int u,int v,vector<int>& parent,vector<int>& rank){
        int pu=find(u,parent);
        int pv=find(v,parent);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else{
            parent[pu]=pv;
            rank[pu]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> result;
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        vector<int> rank(n+1,0);
        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];
            int pu=find(u,parent);
            int pv=find(v,parent);
            if(pu==pv){
                result.push_back(u);
                result.push_back(v);
                return result;
            }
            else{
                uniont(u,v,parent,rank);
            }
        }
        return result;
    }
};
