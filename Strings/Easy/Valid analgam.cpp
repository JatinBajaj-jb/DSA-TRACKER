//Approach 1: just used a simple hash map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        for(char val:s){
            mp1[val]++;
        }
        for(char val:t){
            mp1[val]--;
        }
        for(auto val:mp1){
            if(val.second!=0){
                return false;
            }
        }
        return true;
    }
};
