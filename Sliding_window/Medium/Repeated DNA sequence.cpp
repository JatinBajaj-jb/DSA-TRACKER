// Approach 1 : I used the original sliding window template to solve the question
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string,int> mp;
        int right=0;
        string curr="";
        while(right<10){
            curr+=s[right++];
        }
        mp[curr]++;
        for(right;right<s.length();right++){
            curr+=s[right];
            curr.erase(0,1);
            if(mp[curr]==1){
                result.push_back(curr);
                mp[curr]++;
            }
            else{
                mp[curr]++;
            }
        }
        return result;  
    }
};

// Approach 2 : I used bit manipulation to solve the question (we converted 80 bits per 10 char to 20 bytes and stored it in 32 bit int )
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<int,int> mp;

        unordered_map<char,int> convert={{'A',0},{'C',1},{'G',2},{'T',3}};

        int window=0;
        for(int i=0;i<10;i++){
            window =(window << 2) | convert[s[i]];
        }
        mp[window]++;
        
        int mask=(1 <<20) -1;
        for(int i=10;i<s.length();i++){
            window=((window <<2)|convert[s[i]]) & mask;

            if(mp[window]==1){
                result.push_back(s.substr(i-9,10));
            }
            mp[window]++;
        }
        return result;
    }
};
