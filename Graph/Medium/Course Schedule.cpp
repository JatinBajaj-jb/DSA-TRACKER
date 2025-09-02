// Approach 1: I applied the topologival sort for the cycle detection in a DAG :
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        queue<int> q;
        int count=0;
        vector<int> indegree (numCourses,0);
        for(auto vec:prerequisites){
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            count++;
            for(int& v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return count==numCourses;
    }
};

// Approach 2: I used Dfs for cycle detection in directed graphs :
class Solution {
private:
    bool dfs(int u,vector<bool>& visited,unordered_map<int,vector<int>>& mp,vector<bool>& inrecursion){
        visited[u]=true;
        inrecursion[u]=true;
        for(int& v:mp[u]){
            if(!visited[v] &&  dfs(v,visited,mp,inrecursion)){
                return true;
            }else if(inrecursion[v]){
                return true;
            }
        }
        inrecursion[u]=false;
        return false;
    }
public:
    bool canFinish(int nC, vector<vector<int>>& pq) {
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(nC,false);
        vector<bool> inrecursion(nC,false);
        for(auto vec:pq){
            mp[vec[1]].push_back(vec[0]);
        }
        for(int i=0;i<nC;i++){
            if(!visited[i] && dfs(i,visited,mp,inrecursion)){
                return false;
            }
        }
        return true;
    }
};

