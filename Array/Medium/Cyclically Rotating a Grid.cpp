// Approach 1 : I used 1-D array to find the solution of the problem 
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int startR=0;
        int startC=0;
        int endR=grid.size()-1;
        int endC=grid[0].size()-1;
        
        int loops=min(grid.size(),grid[0].size())/2;
        while(loops--){
            int size=(endR-startR+1)*2+(endC-startC+1)*2-4;
            vector<int> mat(size,0);
            int curr=0;
            for(int i=startR;i<=endR;i++){
                int indx=(curr+k)%size;
                mat[indx]=grid[i][startC];
                curr++;
            }
            for(int j=startC+1;j<=endC;j++){
                int indx=(curr+k)%size;
                mat[indx]=grid[endR][j];
                curr++;
            }
            for(int i=endR-1;i>=startR;i--){
                int indx=(curr+k)%size;
                mat[indx]=grid[i][endC];
                curr++;
            }
            for(int j=endC-1;j>startC;j--){
                int indx=(curr+k)%size;
                mat[indx]=grid[startR][j];
                curr++;
            }
            curr=0;
            for(int i=startR;i<=endR;i++){
                grid[i][startC]=mat[curr++];                
            }
            for(int j=startC+1;j<=endC;j++){
                grid[endR][j]=mat[curr++];
            }
            for(int i=endR-1;i>=startR;i--){
                grid[i][endC]=mat[curr++];
            }
            for(int j=endC-1;j>startC;j--){
                grid[startR][j]=mat[curr++];
            }
            startR++;
            endR--;
            startC++;
            endC--;
        }
        return grid;
    }
};
