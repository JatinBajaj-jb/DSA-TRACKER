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
