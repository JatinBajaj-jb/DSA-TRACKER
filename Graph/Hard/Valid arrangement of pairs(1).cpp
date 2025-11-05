// Approach : I used heirholzer's algorithm to find the solution
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size()+1;
        vector<vector<int>> result;
        unordered_map<int,int> outd,ind;
        unordered_map<int,vector<int>> adj;
        for(auto& vec:pairs){
            adj[vec[0]].push_back(vec[1]);
            outd[vec[0]]++;
            ind[vec[1]]++;
        }
        int snode=pairs[0][0];
        for(auto& it:adj){
            if(outd[it.first]-ind[it.first]==1){
                snode=it.first;
                break;
            }
        }

        stack<int> st;
        st.push(snode);
        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int nx=adj[curr].back();
                adj[curr].pop_back();
                st.push(nx);
            }
        }
        vector<int>path;
        while(!st.empty()){
            path.push_back(st.top());
            st.pop();
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size()-1;i++){
            result.push_back({path[i],path[i+1]});
        }
        return result;
    }
};
