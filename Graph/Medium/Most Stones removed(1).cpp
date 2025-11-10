// Approach 1 : I used dfs
class Solution {
private:
    void dfs(vector<vector<int>>& adj,int i,vector<bool>& visited){
        visited[i]=true;
        for(int v:adj[i]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
        return;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(stones[j]!=stones[i] && (stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                visited[i]=false;
            }
        }
        int result=0;
        for(bool val:visited){
            if(val) result++;
        }
        return result;
    }
};

// Approach 2 : DSU
class Solution {
    int find(int i,vector<int>& parent){
        if(i==parent[i]) return i;
        else{
            return parent[i]=find(parent[i],parent);
        }
    }
    void uniont(int u,int v,vector<int>& rank,vector<int>& parent){
        int p_u=find(u,parent);
        int p_v=find(v,parent);
        if(rank[p_u]>rank[p_v]){
            parent[p_v]=u;
        }
        if(rank[p_v]>rank[p_u]){
            parent[p_u]=v;
        }
        else {
            parent[p_v]=u;
            rank[p_v]++;
        }
        return;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int result=0;
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    int i_p=find(i,parent);
                    int j_p=find(j,parent);
                    if(i_p!=j_p){
                        uniont(i_p,j_p,rank,parent);
                        result++;
                    }
                }
            }

        }
        return result;
    }
};

// Approach 2 : I used dsu with unordered_map for row and column 
class Solution {
    int find(int i,vector<int>& parent){
        if(i==parent[i]) return i;
        else{
            return parent[i]=find(parent[i],parent);
        }
    }
    void uniont(int u,int v,vector<int>& rank,vector<int>& parent){
        int p_u=find(u,parent);
        int p_v=find(v,parent);
        if(rank[p_u]>rank[p_v]){
            parent[p_v]=p_u;
        }
        if(rank[p_v]>rank[p_u]){
            parent[p_u]=p_v;
        }
        else {
            parent[p_v]=p_u;
            rank[p_v]++;
        }
        return;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int result=0;
        unordered_map<int,vector<int>> row,col;
        for(int i=0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,1);

        for(auto[_,vec]:row){
            int p_u=find(vec[0],parent);
            for(int i=1;i<vec.size();i++){
                int p_v=find(vec[i],parent);
                if(p_u!=p_v){
                    uniont(p_u,p_v,rank,parent);
                }
            }
        }
        for(auto[_,vec]:col){
            int p_u=find(vec[0],parent);
            for(int i=1;i<vec.size();i++){
                int p_v=find(vec[i],parent);
                if(p_u!=p_v){
                    uniont(p_u,p_v,rank,parent);
                }
            }
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(find(i,parent));
        }
        return n-st.size();
    }
};
