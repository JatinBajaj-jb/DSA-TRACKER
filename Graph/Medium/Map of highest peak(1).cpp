// Approach : I used mutli source bfs;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    pq.push({i,j});
                }
            }
        }
        vector<vector<int>> grid(n,vector<int>(m,0));
        int level=1;
        while(!pq.empty()){
            int n1=pq.size();
            while(n1--){
                auto[i,j]=pq.front();
                pq.pop();
                for(auto& [x,y]:dir){
                    int ni=i+x;
                    int nj=j+y;
                    if(ni>=0 && nj>=0 && ni<n && nj<m && isWater[ni][nj]==0){
                        grid[ni][nj]=level;
                        isWater[ni][nj]=2;
                        pq.push({ni,nj});
                    }
                }
            }
            level++;
        }

        return grid;
    }
};
