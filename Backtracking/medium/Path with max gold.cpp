//Approach - I just used backtracking , it was a bit difficult since i faced difficulties in getting the return <int_type> part , but overall good question
class Solution {
vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
private:
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            return 0;
        }
        int sum=0;
        int temp=grid[i][j];
        grid[i][j]=0;
        for(auto d:dir){
            int i_=i+d.first;
            int j_=j+d.second;
            sum=max(sum,solve(grid,i_,j_,m,n));
        }
        grid[i][j]=temp;
        return sum+temp;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,solve(grid,i,j,m,n));
                }
            }
        }
        if(ans!=INT_MIN){
            return ans;
        }
        else{
            return 0;
        }    
    }
};
