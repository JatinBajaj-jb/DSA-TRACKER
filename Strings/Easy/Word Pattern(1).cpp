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

// Attempt 2: I solved the question by using the same method 
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp1;
        unordered_map<char,string> mp2;
        int indx=0;
        int count=0;
        string temp="";
        stringstream ss(s); 
        while(getline(ss,temp,' ')){
            count++;
            if(count>pattern.size()) return false;
            if(mp1.find(temp)==mp1.end()){
                if(mp2.find(pattern[indx])==mp2.end()){
                    mp1[temp]=pattern[indx];
                    mp2[pattern[indx]]=temp;
                }
                else return false;
            }
            else{
                if(mp1[temp]!=pattern[indx] || mp2[pattern[indx]]!=temp)return false;
            }
            indx++;
        }
        return indx==pattern.length();
    }
};
