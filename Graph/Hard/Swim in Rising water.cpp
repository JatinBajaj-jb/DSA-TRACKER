// Approach 1 : i used binary search on all the possible t values i,e from grid[0][0] to max value of grid(n(2)-1) and then applied bfs ;
class Solution {
public:
    vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    int n;
    bool pos(int t,int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited){
        if(i<0 || j<0 ||i>=n || j>=n || grid[i][j]==-1 || grid[i][j]>t || visited[i][j]==true){
            return false;
        }
        if(i==n-1 && j==n-1){
            return true;
        }
        visited[i][j]=true;
        for(vector v:dir){
            int i_=i+v[0];
            int j_=j+v[1];
            if(pos(t,i_,j_,grid,visited)){
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid){
        int result=-1;
        n=grid.size();
        int l=grid[0][0];
        int r=n*n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>> visited(n,vector<bool>(n,false));
            if(pos(mid,0,0,grid,visited)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};
