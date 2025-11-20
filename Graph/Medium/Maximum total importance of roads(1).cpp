class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for(auto& vec:roads){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({degree[i],i});
        }
        vector<int> p(n);
        int currp=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            p[it.second]=currp;
            currp++;
        }
        long long result=0;
        for(auto& vec:roads){
            result+=p[vec[0]];
            result+=p[vec[1]];
        }
        return result;
    }
};

// Approach 2 : I just sorted the degree vector and multiple it with the priority from lowest to highest 
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for(auto& vec:roads){
            int u=vec[0];
            int v=vec[1];
            degree[u]++;
            degree[v]++;
        }
        long long currp=1;
        long long result=0;
        sort(degree.begin(),degree.end());
        for(int val :degree){
            result+=(val*currp);
            currp++;
        }
       
        return result;
    }
};

