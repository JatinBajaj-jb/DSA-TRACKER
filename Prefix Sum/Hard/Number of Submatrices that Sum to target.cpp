// Approach 1: I used a prefix approach where i converted 2 -d array problem to 1-d array problem by summing all the values of the rows and then doing 
// column by column prefix approach 

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int currsum=0;
            for(int j=0;j<m;j++){
                currsum+=matrix[i][j];
                matrix[i][j]=currsum;
            }
        }

        for(int startcol=0;startcol<m;startcol++){

            for(int j=startcol;j<m;j++){
                unordered_map<int,int> mp;
                mp[0]++;
                int currsum=0;
                for(int i=0;i<n;i++){
                    currsum+=matrix[i][j]-(startcol>0?matrix[i][j-1]:0);
                    if(mp.find(currsum-target)!=mp.end()){
                        count+=mp[currsum-target];
                    }
                    mp[currsum]++;
                }
            }
        }
        return count;

        
    }
};
