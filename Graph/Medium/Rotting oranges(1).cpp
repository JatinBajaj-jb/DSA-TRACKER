// Approach : I used muti sorce bfs;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        int n=grid.size();
        int m=grid[0].size();
        int freshor=0;
        int result=0;
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    freshor++;
                }
                else if(grid[i][j]==2){
                    pq.push({i,j});
                }
            }
        }
        while(!pq.empty()){
            int n=pq.size();
            while(n--){
                auto[i,j]=pq.front();
                pq.pop();
                for(auto [x,y]:dir){
                    int i1=i+x;
                    int j1=j+y;
                    
                    if(i1>=0 && j1>=0 && i1<n && j1<m && grid[i1][j1]==1){
                        grid[i1][j1]=0;
                        freshor--;
                        pq.push({i1,j1});
                    }
                }
            }
            result++;
        }
        if(freshor!=0){
            return -1;
        }
        else{
            return result;
        }
    }
};
