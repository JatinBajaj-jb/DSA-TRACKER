// Approch: I used Dijkstar algorithmn and got the max element of the result as answer;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(n+1,INT_MAX);

        for(auto& vec:times){
            mp[vec[0]].push_back({vec[1],vec[2]});
            // mp[vec[1]].push_back({vec[0],vec[2]});
        }
        pq.push({0,k});
        result[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto& it:mp[node]){
                int d=it.second;
                int Anode=it.first;
                if(d+dist<result[Anode]){
                    result[Anode]=d+dist;
                    pq.push({d+dist,Anode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(result[i]==INT_MAX) return -1;
            ans=max(ans,result[i]);
        }    
        return ans;    
    }
};
