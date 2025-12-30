// Approach 1 : I used dijstars algo 
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        struct Edge{
            int to,st,end;
        };
        vector<vector<Edge>> adj(n);
        for(auto& vec:edges){
            adj[vec[0]].push_back({vec[1],vec[2],vec[3]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [u,t]=pq.top();
            pq.pop();
            if(u==n-1) return t;
            for(auto vec:adj[u]){
                int v=vec.to;
                int mint=vec.st;
                int maxt=vec.end;
                if(t<mint){
                    pq.push({v,mint+1});
                }
                else if(t>maxt) continue;
                else{
                    pq.push({v,t+1});
                }
            }
        }
        return -1;
    }

};
// Approach 2 : i used a vector dist to track the minimum time for each node and to remove tle 
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        struct Edge{
            int to,st,end;
        };
        vector<vector<Edge>> adj(n);
        vector<int> dist(n,INT_MAX);
        for(auto& vec:edges){
            adj[vec[0]].push_back({vec[1],vec[2],vec[3]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto [t,u]=pq.top();
            pq.pop();
            if(t>dist[u]) continue;
        
            if(u==n-1) return t;
            for(auto vec:adj[u]){
                int v=vec.to;
                int mint=vec.st;
                int maxt=vec.end;
                int newTime=0;
                if(t<mint){
                    newTime=mint+1;
                }
                else if(t>maxt) continue;
                else{
                   newTime=t+1;
                }
                if(newTime<=dist[v]){
                    dist[v]=newTime;
                    pq.push({newTime,v});
                }
            }
        }
        return -1;
    }

};
