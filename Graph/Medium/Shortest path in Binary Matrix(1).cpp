// Approach 1 : I used bfs search to get the shortest path , i made several mistakes at first of incrementing counter by 1 on every node , it should had been on every level
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        queue<pair<int,int>> qu;
        int count=0;

        qu.push({0,0});
        grid[0][0]=1;
        while(!qu.empty()){
            int N=qu.size();
            while(N--){
                int i=qu.front().first;
                int j=qu.front().second;
            
                qu.pop();
                if(i==n-1 && j==m-1){
                    return count+1;
                }
                for(auto val:dir){
                    int i1=i+val.first;
                    int j1=j+val.second;
                    if(i1>=0 && j1>=0 && i1<n && j1<n && grid[i1][j1]==0){
                        qu.push({i1,j1});
                        grid[i1][j1]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
// Approach 2 : I used dijkstar's algorithmn to find the path , and got to know that is had larger time complexity :
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
               
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        grid[0][0]=1;

        while(!pq.empty()){
            auto it=pq.top();
            int i=it.second.first;
            int j=it.second.second;
            int d=it.first;
            pq.pop();

            if(i==n-1 && j==m-1){
                return d+1;
            }
            for(auto de:dir){
                int i1=i+de.first;
                int j1=j+de.second;
                if(i1>=0 && j1>=0 && i1<n && j1<m && grid[i1][j1]==0){
                    if(d+1<result[i1][j1]){
                        result[i1][j1]=d+1;
                        pq.push({d+1,{i1,j1}});
                    }
                }
            }
        }
        return -1;
    }
};

};
