// Approach : I used dfs:
class Solution {
private:
    bool dfs(int u,vector<vector<int>>& graph,vector<int>& colour,int currcol){
        colour[u]=currcol;
        for(int& v:graph[u]){
            if(colour[v]==currcol){
                return false;
            }
            if(colour[v]==-1){
                int colv=1-currcol;
                if(!dfs(v,graph,colour,colv)){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colour[i]==-1 && !dfs(i,graph,colour,1)){
                return false;
            }
        }
        return true;
        
    }
};
