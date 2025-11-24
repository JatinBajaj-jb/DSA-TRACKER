// Approach : I used two unordered map
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char ,string> mp;
        unordered_map<string,char> mp1;
        int indx=0;
        string temp;
        stringstream ss(s);
        while(getline(ss,temp,' ')){
            if(indx>=pattern.length()) return false;

            if(mp.find(pattern[indx])!=mp.end()){
                if(mp[pattern[indx]]!=temp) return false;
            }
            else if(mp1.find(temp)!=mp1.end()){
                if(mp1[temp]!=pattern[indx]) return false;
            }
            else{
                mp1[temp]=pattern[indx];
                mp[pattern[indx]]=temp;
            }
            indx++;
        }
        return indx==pattern.length();   
    }
};
