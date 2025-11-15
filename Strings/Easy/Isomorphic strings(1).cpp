// Approach : I used two hash set
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp,mp2;
        if(s.size()!=t.size()){
            return false;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
            char s1=s[i];
            char s2=t[i];
            if(mp.find(s1)==mp.end()){
                mp[s1]=s2;
            }
            else{
                if(mp[s1]!=s2) return false;
            } 
            if(mp2.find(s2)==mp2.end()){
                mp2[s2]=s1;
            }
            else{
                if(mp2[s2]!=s1) return false;
            }
        }
        return true;
    }
};
// Approach 2 : I used vectors 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        int m=t.length();

        if(n!=m) return false;
        vector<int> map1(256,-1);
        vector<int> map2(256,-1);
        for(int i=0;i<n;i++){
            char s1=s[i];
            char s2=t[i];
            if(map1[s1]==-1 && map2[s2]==-1){
                map1[s1]=s2;
                map2[s2]=s1;
            }
            else{
                if(map1[s1]!=s2 || map2[s2]!=s1){
                    return false;
                }
            }
        }
        return true;
    }
};
