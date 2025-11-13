// Approach 1 :I used dsu
class Solution {
private:
    int find(int a,vector<int>&parent){
        if(a==parent[a]) return a;
        return parent[a]=find(parent[a],parent);
    }
    void unite(int a,int b,vector<int>& parent,vector<int>& rank){
        int pa=find(a,parent);
        int pb=find(b,parent);
        if(pa==pb) return ;
        if(rank[pa]>rank[pb]){
            parent[pb]=pa;
        }
        else if(rank[pb]>rank[pa]){
            parent[pa]=pb;
        }
        else{
            parent[pa]=pb;
            rank[pb]++;
        }
        return;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto vec:dislikes){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int>parent(n+1);
        vector<int>rank(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=1;i<=n;i++){
            if(adj[i].empty()) continue;
        
            int temp=-1;
            int pa=find(i,parent);
            for(auto v:adj[i]){
                int pb=find(v,parent);
                if(pb==pa)return false;
                if(temp!=-1){
                    unite(pb,temp,parent,rank);
                }
                temp=pb;
            }
        }
        return true; 
    }
};

// Approach 2 : I used dfs
class Solution {
private:
    bool dfs(vector<int>& colour,vector<vector<int>>& adj,int u,int currcol){
        colour[u]=currcol;
        for(auto v:adj[u]){
            if(colour[v]==currcol){
                return false;
            }
            if(colour[v]==-1 && !dfs(colour,adj,v,1-currcol)){
                return false;
            }
        }
        return true;

    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto vec:dislikes){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int> colour(n+1,-1);
        for(int i=1;i<n;i++){
            if(colour[i]==-1 && !dfs(colour,adj,i,0)){
                return false;
            }
        }
        return true;

    }
};
