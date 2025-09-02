// Approach 1: I used BFS:
class Solution {
public:
    vector<int> findOrder(int nC, vector<vector<int>>& pq) {
        vector<int> indegree(nC,0);
        vector<int> result;
        unordered_map<int,vector<int>> mp;
        queue<int> q;
        for(auto vec:pq){
            mp[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }
        for(int i=0;i<nC;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            count++;
            q.pop();
            for(int& v:mp[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        vector<int> temp;
        return count==nC?result:temp;
    }
};

// Approach 2: Dfs approch :
class Solution {
private:
    bool dfs(int u, unordered_map<int,vector<int>>& mp,stack<int>& result, vector<bool>& visited, vector<bool>& inrecursion){
        visited[u]=true;
        inrecursion[u]=true;
        for(int& v:mp[u]){
            if(!visited[v] && dfs(v,mp,result,visited,inrecursion)){
                return true;
            }else if(inrecursion[v]){
                return true;
            }
        }
        inrecursion[u]=false;
        result.push(u);
        return false;
    }
public:
    vector<int> findOrder(int nC, vector<vector<int>>& pq) {
        bool check=false;
        vector<bool> visited(nC,false);
        vector<bool> inrecursion(nC,false);
        stack<int> result;
        unordered_map<int,vector<int>> mp;
        for(auto vec:pq){
            mp[vec[1]].push_back(vec[0]);
        }
        for(int i=0;i<nC;i++){
            if(!visited[i] && dfs(i,mp,result,visited,inrecursion)){
                check=true;
                break;
            }
        }
        vector<int> temp;
        if(!check){
            while(!result.empty()){
                int curr=result.top();
                temp.push_back(curr);
                result.pop();
            }
        }
        return temp;
    }
};


