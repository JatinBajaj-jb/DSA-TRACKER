// Approach 1 : I solved the question using dsu where i grouped the elements on the basis of their ablitiy to swap with each other 
class Solution {
private:
    int find(int i,vector<int>& parent){
        if(i==parent[i]) return i;

        return parent[i]=find(parent[i],parent);
    }

    void uniont(int u,int v ,vector<int>& parent,vector<int>& rank){
        int pU=find(u,parent);
        int pV=find(v,parent);

        if(pU==pV) return;

        if(rank[pU]>rank[pV]){
            parent[pV]=pU;
        }
        else if(rank[pU]<rank[pV]){
            parent[pU]=pV;
        }
        else{
            parent[pU]=pV;
            rank[pV]++;
        }
        return;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int result=0;
        int n=source.size();

        unordered_map<int,unordered_map<int,int>> groupfreq;

        vector<int> parent(n);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto vec:allowedSwaps){
            int u=vec[0];
            int v=vec[1];
            uniont(u,v,parent,rank);
        }

        for(int i=0;i<n;i++){
            int curr=source[i];
            int p=find(i,parent);
            groupfreq[p][curr]++;
        }
        for(int i=0;i<n;i++){
            int p=find(i,parent);
            if(groupfreq[p][target[i]]>0){
                groupfreq[p][target[i]]--;
            }
            else{
                result++;
            }
        }
        return result;
    }
};
