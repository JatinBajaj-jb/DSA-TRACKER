//Approach : I used the dsu approach to solve this question ,basic find and union approach but with a hash map to convert the characters into intergers or index;
class Solution {
private:
    int find(int indx,vector<int>& parent){
        if(indx==parent[indx]){
            return indx;
        }
        else{
            return find(parent[indx],parent);            
        }
    }
    void un(char x,char y,vector<int>& parent,unordered_map<char,int>& mp){
        int p_1=find(mp[x],parent);
        int p_2=find(mp[y],parent);
        if(p_1==p_2){
            return;
        }
        else{
            parent[p_2]=p_1;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        int indx=0;
        unordered_map<char,int> mp;
        for(string st:equations){
            if(mp.find(st[0])==mp.end()){
                mp[st[0]]=indx++;
            }
            if(mp.find(st[3])==mp.end()){
                mp[st[3]]=indx++;
            }
        }
        vector<int> parent;
        for(int i=0;i<mp.size();i++){
            parent.push_back(i);
        }

        for(string val:equations){
            if(val[1]=='='){
                un(val[0],val[3],parent,mp);
            }
        }
        for(string val:equations){
            if(val[1]=='!'){
                int p1=find(mp[val[0]],parent);
                int p2=find(mp[val[3]],parent);
                if(p1==p2){
                    return false;
                }
            }
        }
        return true;

    }

};
// Approach 2 : I used the same dsu approach but without the map as i just passes val[i]-'a' to get the indx value and slight optimization of ranking and path compression
class Solution {
private:
    int find(int indx,vector<int>& parent){
        if(indx==parent[indx]){
            return indx;
        }
        else{
            return parent[indx]=find(parent[indx],parent);            
        }
    }
    void un(int x,int y,vector<int>& parent,vector<int>& rank){
        int p_1=find(x,parent);
        int p_2=find(y,parent);
        if(p_1==p_2){
            return;
        }
        else{
            if(rank[p_1]==rank[p_2]){
                parent[p_2]=p_1;
                rank[p_1]++;
            }
            else if(rank[p_1]>rank[p_2]){
                parent[p_1]=p_2;
            }
            else{
                parent[p_2]=p_1;
            }
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        int indx=0;
        unordered_map<char,int> mp;
        vector<int> parent(26);
        vector<int> rank(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string val:equations){
            if(val[1]=='='){
                un(val[0]-'a',val[3]-'a',parent,rank);
            }
        }
        for(string val:equations){
            if(val[1]=='!'){
                int p1=find(val[0]-'a',parent);
                int p2=find(val[3]-'a',parent);
                if(p1==p2){
                    return false;
                }
            }
        }
        return true;
        
    }
};

