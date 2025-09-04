// Approach : I used dsu approach to find the total number of not connected nodes and returned nodes-1;
class Solution {
private:
    int find(int i,vector<int>& parent){
        if(i==parent[i]){
            return i;
        }
        else{
             return parent[i]=find(parent[i],parent);
        }
    }
    void un(int x,int y ,vector<int>& parent,vector<int>& rank){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px==py){
            return;
        }else{
            if(rank[px]==rank[py]){
                parent[py]=px;
                rank[px]++;
            }
            else if(rank[px]>rank[py]){
                parent[py]=px;
            }
            else{
                parent[px]=py;
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int> rank(n,0);
        int components=n;
        for(vector<int> vec:connections){
            if(find(vec[0],parent)!=find(vec[1],parent)){
                un(vec[0],vec[1],parent,rank);
                components--;
            }
        }
        return components-1;
        
    }
};
