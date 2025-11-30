// Approach 1 : I used dfs to track the number of groups 
class Solution {
private:   
    bool isSimilar(string& s1,string& s2){
        int n=s1.length();
        int m=s2.length();
        if(n!=m) return false;
        int diff=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) diff++;
        }
        return (diff==2 || diff==0);
    }
    void dfs(int u,vector<bool>& visited,vector<vector<int>>& adj){
        visited[u]=true;
        for(int v:adj[u]){
            if(!visited[v]){
                dfs(v,visited,adj);
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int result=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                result++;
                dfs(i,visited,adj);
            }
        }
        return result;        
    }
};

// Approach 2 : I used dsu 
class Solution {
private:   
    bool isSimilar(string& s1,string& s2){
        int n=s1.length();
        int m=s2.length();
        if(n!=m) return false;
        int diff=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) diff++;
        }
        return (diff==2 || diff==0);
    }
    void uniont(int u,int v,vector<int>& rank,vector<int>& parent){
        int pu=find(u,parent);
        int pv=find(v,parent);

        if(pu==pv) return;
        else{
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu]){
                parent[pu]=pv;
            }
            else{
                parent[pu]=pv;
                rank[pv]++;
            }
        }
    }
    int find(int i,vector<int>& parent){
        if(parent[i]==i) return i;

        return parent[i]=find(parent[i],parent);
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int result=0;
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])){
                    uniont(i,j,rank,parent);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                result++;
            }
        }
        return result;
    }
};
