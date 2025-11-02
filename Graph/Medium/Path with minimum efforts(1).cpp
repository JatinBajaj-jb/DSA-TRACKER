// Approach : I used dijkstar's algorithmn to find the max difference along the shortest path "
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<pair<int,int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        result[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            int i=it.second.first;
            int j=it.second.second;
            int s1=it.first;
            pq.pop();
            for(auto d:dir){
                int i1=i+d.first;
                int j1=j+d.second;
                if(i1>=0 && i1<n && j1>=0 && j1<m){
                    int currd=abs(heights[i1][j1]-heights[i][j]);
                    int maxd=max(currd,s1);
                    if(maxd<result[i1][j1]){
                        result[i1][j1]=maxd;
                        pq.push({maxd,{i1,j1}});
                    }
                }
            }
        }
        if(result[n-1][m-1]==INT_MAX){
            return -1;
        }
        else{
            return result[n-1][m-1];
        }
    }
};
