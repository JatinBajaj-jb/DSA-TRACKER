// Attempt 1 : I tried to generalize the graph method and then solve the question using dfs , it lead to multiple failure points 
class Solution {
private:
    void dfs(int u,vector<bool>& visited,unordered_map<int,vector<int>>& mp){
        if(visited[u]) return;
        visited[u]=true;


        for(auto& v:mp[u]){
            if(!visited[v]){
                dfs(v,visited,mp);
            }
        }
        return;
    } 
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int result=0;
        unordered_map<int,vector<int>> mp;
        vector<pair<int,int>> moves={{-1,0},{1,0},{0,1},{0,-1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(auto p:moves){
                        int i1=i+p.first;
                        int j1=j+p.second;

                        if(i1>=0 && j1>=0 && i1<n && j1<m && grid[i1][j1]==1){
                            int oldCords=i*10+j;
                            int newCords=i1*10+j1;
                            mp[oldCords].push_back(newCords);
                        }
                    }
                }
            }
        }

        vector<bool> visited(n*m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(visited[i*10+j]==false){
                        result++;
                        dfs(i*10+j,visited,mp);
                    }
                }
            }
        }
        return result;
    }
};

// Approach 1 : I tried simple dfs
class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int result=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    result++;
                    dfs(i,j,grid);
                }
            }
        }
        return result;
        
    }
};
// Approach 2 : I tried simple bfs approach 
class Solution {
private:
    void bfs(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 ||i>=n||j>=m || grid[i][j]=='0') return;

        vector<pair<int,int>> moves={{-1,0},{1,0},{0,-1},{0,1}};

        queue<int> pq;
        pq.push(i*m+j);
        grid[i][j]='0';

        while(!pq.empty()){
            int top=pq.front();
            pq.pop();
        
            int i1=top /m;
            int j1=top %m;

            for(auto p:moves){
                int i2=i1+p.first;
                int j2=j1+p.second;
                if(i2>=0 && j2>=0 && i2<n && j2<m && grid[i2][j2]=='1'){
                    grid[i2][j2]='0';
                    pq.push(i2*m+j2);
                }
            }    
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         
        int result=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    result++;
                    bfs(i,j,grid);
                }
            }
        }
        return result;
    }
};
// Approach 3 : I tried dsu 
class Solution {
private:
    int find(int u,vector<int>& parent){
        if(u==parent[u]) return u;
        else{
            return parent[u]=find(parent[u],parent);
        }
    }
    void uniont(int u,int v,vector<int>& parent,vector<int>& rank){
        int p1=find(u,parent);
        int p2=find(v,parent);
        if(p1==p2) return;
        else{
            if(rank[p1]>rank[p2]){
                parent[p2]=p1;
            }
            else if(rank[p2]>rank[p1]){
                parent[p1]=p2;
            }
            else{
                parent[p1]=p2;
                rank[p2]++;
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int result=0;

        vector<int> parent(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                parent[i*m+j]=i*m+j;
            }
        }
        vector<int> rank(n*m,0);
        vector<pair<int,int>> moves={{-1,0},{0,-1},{1,0},{0,1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    for(auto& p:moves){
                        int i1=p.first;
                        int j1=p.second;

                        int i2=i+i1;
                        int j2=j+j1;
                        if(i2>=0 && j2>=0 && i2<n && j2<m && grid[i2][j2]=='1'){

                            int p1=find(i*m+j,parent);
                            int p2=find(i2*m+j2,parent);
                            if(p1!=p2){
                                uniont(i*m+j,i2*m+j2,parent,rank);
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    int p=find(i*m+j,parent);
                    if(p==i*m+j) result++;
                }
            }
        }
        return result;
    }
};
