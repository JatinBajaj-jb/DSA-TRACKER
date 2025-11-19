// Approach : We just calculate the indegree and return all values where indegree==0;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto& vec:edges){
            adj[vec[0]].push_back(vec[1]);
            indegree[vec[1]]++;
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) result.push_back(i);
        }
        return result;
    }
};
