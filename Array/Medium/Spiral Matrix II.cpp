// Approach : I just used the basic spiral method approach 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int indx=0;
        int rowz=0;
        int colz=0;
        int rown=n-1;
        int coln=n-1;
        vector<vector<int>> result(n,vector<int>(n,0));
        if(n==1){
            result[0][0]=1;
            return result;
        }
        vector<int> grid;
        for(int i=1;i<=n*n;i++){
            grid.push_back(i);
        }
        while(indx<=n){
            for(int col=colz;col<n;col++){
                result[rowz][col]=grid[indx++];
            }
            for(int row=1;row<n;row++){
                result[row][coln]=grid[indx++];
            }
            for(int col=n-2;col>=0;col--){
                result[rown][col]=grid[indx++];
            }
            for(int row=n-2;row>0;row--){
                result[row][colz]=grid[indx++];
            }
            colz++;
            rowz++;
            coln--;
            rown--;

        }
        return result;
    }
};
