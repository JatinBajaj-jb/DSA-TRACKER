// Approach 1: I used DSU approach to get the number of groups 
class Solution {
private:
    long long find(long long i,vector<long long>& parent){
        if(i==parent[i]){
            return i;
        }
        else{
            return parent[i]=find(parent[i],parent);
        }
    }
    void un(int x,long long  y,vector<long long >& parent,vector<long long >& rank){
        long long  px=find(x,parent);
        long long  py=find(y,parent);
        if(px==py){
            return;
        }
        else{
            if(rank[px]==rank[py]){
                parent[py]=px;
                rank[px]++;
            }
            else if(rank[px]>rank[py]){
                parent[py]=px;
            }
            else{
                parent[px]=py;
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> parent(n);
        vector<long long> rank(n,0);
        unordered_map<int,int> mp;
        long long result=0;
        long long size=n;
        for(long long i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& vec:edges){
            un(vec[0],vec[1],parent,rank);
        }
        for(int i=0;i<n;i++){
            int p=find(i,parent);
            mp[p]++;
        }
        for(auto& i:mp){
            result+=i.second*(size-i.second);
            size=size-i.second;
        }
        return result; 
    }
};

// Approach 2: I used DFS :
class Solution {
private:
    void dfs(int u,vector<bool>& visited,unordered_map<int,vector<int>>& mp,long long& c){
        visited[u]=true;
        c++;
        for(int& v:mp[u]){
            if(!visited[v]){
                dfs(v,visited,mp,c);
            }
        }

    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,false);
        int size=n;
        long long result=0;
        for(auto& vec:edges){
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }  
        for(long long i=0;i<n;i++){
            if(!visited[i]){
                long long c=0;
                dfs(i,visited,mp,c);
                result+=c*(size-c); 
                size=size-c;
            }
        }
        return result;
    }
};
