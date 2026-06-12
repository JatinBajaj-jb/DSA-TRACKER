// Attempt 1 : I tried brute forcing to get the solution , resulted in tle 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n=strs.size();

        int group=0;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(visited[i])continue;
            unordered_map<char,int> mp1;
            result[group].push_back(strs[i]);
            string curr=strs[i];
            for(int j=0;j<curr.length();j++){
                mp1[curr[j]]++;
            }
            for(int k=i+1;k<n;k++){
                unordered_map<char,int> mp2;
                string inner=strs[k];
                for(int j1=0;j1<inner.length();j1++){
                    mp2[inner[j1]]++;
                }
                if(mp1==mp2){
                    result[group].push_back(inner);
                    visited[k]=true;
                }
            }
            group++;
        }
        return result;
    }
};
// Approach 2 : I used the sorting method where all the anagrams have the same signature after sorting
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> mp;

        for(string curr:strs){
            string key=curr;
            sort(key.begin(),key.end());
            mp[key].push_back(curr);
        }

        for(auto it:mp){
            result.push_back(it.second);
        }

        return result;     
    }
};




