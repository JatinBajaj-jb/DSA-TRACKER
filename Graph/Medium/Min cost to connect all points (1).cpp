// Approach : I used prims algorithmn to get the solutions 
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool> visited(n,false);
        
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dis=abs(x2-x1)+abs(y2-y1);
                adj[i].push_back({dis,j});
                adj[j].push_back({dis,i});
            }
        }
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(!visited[node]){
                visited[node]=true;
                sum+=d;
                for(auto vec:adj[node]){
                    int v=vec.second;
                    int d1=vec.first;
                    if(!visited[v]){
                        pq.push({d1,v});
                    }
                }
            }
        }
        return sum;   
    }
};

// Approach 2 : I used kruskal's algorithm :
class Solution {
private:
    int find(int u,vector<int>& parent){
        if(u==parent[u]){
            return u;
        }
        else{
            return parent[u]=find(parent[u],parent);
        }
    }
    void uniont(int u,int v,vector<int>& rank,vector<int>& parent){
        int parent_u=find(u,parent);
        int parent_v=find(v,parent);
        if(parent_u==parent_v){
            return;
        }
        if(rank[parent_u]>rank[parent_v]){
            parent[parent_v]=parent_u;
        }
        else if(rank[parent_u]<rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else{
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        }
        return;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> adj;

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dis=abs(x2-x1)+abs(y2-y1);
                adj.push_back({i,j,dis});
            }
        }
        auto comp=[&](const vector<int>&v1,const vector<int>&v2){
            return v1[2]<v2[2];
        };
        sort(adj.begin(),adj.end(),comp);
        int sum=0;
        vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& it: adj){
            int p_u=find(it[0],parent);
            int p_v=find(it[1],parent);
            int wt=it[2];
            if(p_u!=p_v){
                uniont(it[0],it[1],rank,parent);
                sum+=wt;
            }
        }
        return sum;   
    }
}
// Approach 3:I used a slightly different approach in which we go through each point one by one , find the next minimum node to connect and then connect that node
// then update the cost vector from that node 
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int totalCost=0;
        vector<bool>visited(n,false);
        vector<int> cost(n,INT_MAX);
        cost[0]=0;
        for(int i=0;i<n;i++){
            int next=-1;
            for(int j=0;j<n;j++){
                if(!visited[j] &&(next==-1||cost[j]<cost[next])){
                    next=j;
                }
            }
            visited[next]=true;
            totalCost+=cost[next];

            for(int j=0;j<n;j++){
                if(visited[j]) continue;
                int currCost=abs(points[next][0]-points[j][0])+abs(points[next][1]-points[j][1]);
                cost[j]=min(cost[j],currCost);
            }
        }
        return totalCost;
    }
};
