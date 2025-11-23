// Approach : I used dfs along with a unordered map to convert string (a) to int 
class Solution {
private:
    void dfs(int u,int target,double& r1,double temp,vector<bool>& visited,vector<vector<pair<double,int>>>& adj){
        if(u==target){
            r1=temp;
            return ;
        }
        visited[u]=true;
        for(auto& v:adj[u]){
            double dis=v.first;
            if(!visited[v.second]){
                dfs(v.second,target,r1,temp*dis,visited,adj);
            }
        }
        return;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,int> mp;
        
        int indx=0;
        int curri=0;
        
        for(auto& vec:equations){
            string u=vec[0];
            string v=vec[1];
            if(!mp.count(u)) mp[u]=curri++;
            if(!mp.count(v)) mp[v]=curri++;
        }
        vector<vector<pair<double,int>>> adj(curri);
        for(auto& vec:equations){
            string u=vec[0];
            string v=vec[1];
            adj[mp[u]].push_back({values[indx],mp[v]});
            adj[mp[v]].push_back({1/values[indx],mp[u]});
            indx++;
        }
        vector<bool> visited(curri,false);
        vector<double> result;

        for(auto& vec:queries){
            if(mp.find(vec[0])==mp.end() || mp.find(vec[1])==mp.end())  result.push_back(-1);
            else if(vec[0]==vec[1]) result.push_back(1);
            else{
                double curr=-1;
                double temp=1;
                dfs(mp[vec[0]],mp[vec[1]],curr,temp,visited,adj);
                result.push_back(curr);
                fill(visited.begin(),visited.end(),false);
            }
        }
        return result;
    }
};
