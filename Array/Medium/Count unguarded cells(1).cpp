// Approch 1: I used brute force soltuion :class Solution {
private:
    void solve(int row,int col,vector<vector<int>> &grid,int m,int n){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==2 || grid[i][col]==3){
                break;
            }
            grid[i][col]=1;
        }
        for(int i=row+1;i<m;i++){
            if(grid[i][col]==2 || grid[i][col]==3){
                break;
            }
            grid[i][col]=1;
        }
        for(int j=col-1;j>=0;j--){
            if(grid[row][j]==2 || grid[row][j]==3){
                break;
            }
            grid[row][j]=1;
        }
        for(int j=col+1;j<n;j++){
            if(grid[row][j]==2 || grid[row][j]==3){
                break;
            }
            grid[row][j]=1;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int count=0;
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto val:walls){
            int i=val[0];
            int j=val[1];
            grid[i][j]=2;
        }
        for(auto val:guards){
            int i=val[0];
            int j=val[1];
            grid[i][j]=3;
        }
        for(auto val:guards){
            int i=val[0];
            int j=val[1];
            solve(i,j,grid,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};

// Approach 2 : I marked all the guards and walls and then did 2 horizontal and 2 vertical sweeps 
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int count=0;
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto vec:walls){
            grid[vec[0]][vec[1]]=2;
        }
        for(auto vec:guards){
            grid[vec[0]][vec[1]]=3;
        }
        for(int i=0;i<m;i++){
            bool seen=false;
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    seen=false;
                }
                else if(grid[i][j]==3){
                    seen=true;
                }
                else if(seen){
                    grid[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            bool seen=false;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==2){
                    seen=false;
                }
                else if(grid[i][j]==3){
                    seen=true;
                }
                else if(seen){
                    grid[i][j]=1;
                }
            }
        }
        for(int j=0;j<n;j++){
            bool seen=false;
            for(int i=0;i<m;i++){
                if(grid[i][j]==2){
                    seen=false;
                }
                else if(grid[i][j]==3){
                    seen=true;
                }
                else if(seen){
                    grid[i][j]=1;
                }
            }
        }
        for(int j=0;j<n;j++){
            bool seen=false;
            for(int i=m-1;i>=0;i--){
                if(grid[i][j]==2){
                    seen=false;
                }
                else if(grid[i][j]==3){
                    seen=true;
                }
                else if(seen){
                    grid[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};


