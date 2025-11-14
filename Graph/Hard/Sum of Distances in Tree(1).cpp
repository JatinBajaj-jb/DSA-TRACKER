// Approach 1 : I used bfs on each node ;
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto vec:edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            vector<int>visited(n,false);
            int distance=0;
            queue<pair<int,int>> pq;
            pq.push({i,0});
            visited[i]=true;
            while(!pq.empty()){
                auto [node,dis]=pq.front();
                distance+=dis;
                pq.pop();
                for(auto& v:adj[node]){
                    if(!visited[v]){
                        pq.push({v,dis+1});
                        visited[v]=true;
                    }
                }
            }
            result.push_back(distance);
        }
        return result;
    }
};

// Approach 2 : I used 2 dfs and a subcount , so result[v]=result[parent]-subnodes[v]+(parentnode);
class Solution {
private:
    int dfs1(vector<vector<int>>& adj,int u,int p,int depth,vector<int>& subcount,int& r){
        int tc=1;
        r+=depth;
        for(int& v:adj[u]){
            if(v==p) continue;
            tc+=dfs1(adj,v,u,depth+1,subcount,r);
        }
        subcount[u]=tc;
        return tc;
    }
    void dfs2(vector<vector<int>>& adj,vector<int>& subcount,vector<int>& result,int u,int p,int n){
        for(int& v:adj[u]){
            if(v==p) continue;
            result[v]=result[u]-subcount[v]+(n-subcount[v]);
            dfs2(adj,subcount,result,v,u,n);
        }
        return;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto vec:edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int> result(n);
        vector<int>subcount(n,0);
        int r=0;
        
        dfs1(adj,0,-1,0,subcount,r);
        result[0]=r;
        dfs2(adj,subcount,result,0,-1,n);
        return result;

    }
};



