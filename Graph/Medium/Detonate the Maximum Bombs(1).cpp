// Approach 1: I used dfs 
class Solution {
private:
    double distance(int x,int y,int x1,int y1){
        double sq1=pow((x1-x),2);
        double sq2=pow((y1-y),2);
        return sqrt(sq1+sq2);
    }
    int dfs(int u,vector<vector<int>>& adj,vector<bool>& visited){
        visited[u]=true;
        int curr1=1;
        for(auto& v:adj[u])
            if(!visited[v]){
                curr1+=dfs(v,adj,visited);
            }
        return curr1;
        }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            auto& vec=bombs[i];
            int x=vec[0];
            int y=vec[1];
            int r=vec[2];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                auto& vec1=bombs[j];
                int x1=vec1[0];
                int y1=vec1[1];
                int r1=vec1[2];

                double dis=distance(x,y,x1,y1);
                if(dis<=r){
                    adj[i].push_back(j);
                }
            }
        }
        int result=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            int curr=dfs(i,adj,visited);
            result=max(result,curr);
            fill(visited.begin(),visited.end(),false);
        }
        return result;
    }
};
