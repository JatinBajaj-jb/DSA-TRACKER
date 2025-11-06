// Approach 1 : we used dfs to calculate the diameter of both the trees , if we ought to join the trees , we would merge them from (d)/2 of their lengths respectively ;
class Solution {
private: 
    void dfs(unordered_map<int,vector<int>>& adj,vector<bool>& visited,int node,int &maxd,int& b,int dis){
        if(visited[node]){
            return;
        }
        visited[node]=true;
        if(dis>maxd){
            maxd=dis;
            b=node;
        }
        for(auto& it:adj[node]){
            dfs(adj,visited,it,maxd,b,dis+1);
        }
        return;
    }
    unordered_map<int,vector<int>> get(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> mp;
        for(auto& it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);

        }
        return mp;
    }
    int getd(unordered_map<int,vector<int>>& adj){
        int maxnode=0;
        for(auto it:adj){
            maxnode=max(maxnode,it.first);
            for(auto v:adj[it.first]){
                maxnode=max(maxnode,v);
            }
        }

        vector<bool> visited1(maxnode+1,false);
        vector<bool> visited2(maxnode+1,false);
        int fdis=0;
        int end1=-1;
        dfs(adj,visited1,0,fdis,end1,0);
        int dl=0;
        int end2=-1;
        dfs(adj,visited2,end1,dl,end2,0);
        return dl;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        if(edges1.size()==0 && edges2.size()==0){
            return 1;
        }
        int d1=-1;
        int d2=-1;
        unordered_map<int,vector<int>> adj1=get(edges1);
        unordered_map<int,vector<int>> adj2=get(edges2);
        if(edges1.size()!=0){
            d1=getd(adj1);
        }
        if(edges2.size()!=0){
            d2=getd(adj2);
        }
        
        int combined=(d1+1)/2+(d2+1)/2+1;
        int maxdia=max(d1,d2);

        return max(maxdia,combined);  
    }
};

// Approach 2 :I used bfs :
class Solution {
private:
    pair<int,int> bfs  (unordered_map<int,vector<int>>& adj,int node){
        int maxdis=0;
        int maxnode=node;
        unordered_map<int,bool> visited;
        visited[node]=true;
        queue<int> pq;
        pq.push(node);
        while(!pq.empty()){
            int n=pq.size();
            while(n--){
                int n1=pq.front();
                maxnode=n1;
                pq.pop();
                for(auto it:adj[n1]){
                    if(visited[it]==false){
                        pq.push(it);
                        visited[it]=true;
                    }
                }
            }
            maxdis++;
        }
        return {maxnode,maxdis-1};
    }
    int getd(unordered_map<int,vector<int>>& adj){
        auto[enda,dis]=bfs(adj,adj.begin()->first);
        auto[endb,dia]=bfs(adj,enda);
        return dia;
    }
    unordered_map<int,vector<int>> getmp(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> mp;
        for(auto & it:edges){
            int u=it[0];
            int v=it[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return mp;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        if(edges1.size()==0 && edges2.size()==0){
            return 1;
        }
        unordered_map<int,vector<int>> adj1=getmp(edges1);
        unordered_map<int,vector<int>> adj2=getmp(edges2);
        int d1=-1;
        int d2=-1;
        if(edges1.size()!=0) d1=getd(adj1);
        if(edges2.size()!=0) d2=getd(adj2);

        int maxd=max(d1,d2);
        int combinedd=(d1+1)/2+(d2+1)/2+1;
        return max(maxd,combinedd);
    }
};

