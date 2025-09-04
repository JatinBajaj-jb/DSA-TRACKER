// Approach : I used the unordered_map 
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        set<int> st;
        unordered_map<int,int> mp;
        for(auto& vec:matches){
            st.insert(vec[0]);
            st.insert(vec[1]);
            mp[vec[1]]++;
        }
        for(int player:st){
            if(mp[player]==0){
                ans[0].push_back(player);
            }
            else if(mp[player]==1){
                ans[1].push_back(player);
            }
        }
        return ans;
    }
};
