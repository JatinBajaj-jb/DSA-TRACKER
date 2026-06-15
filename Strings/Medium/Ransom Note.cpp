// Approach 1 : I used vector of alphabets to store the frequency
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);

        for(char& ch:ransomNote){
            freq[ch-'a']++;
        }
        for(char& ch:magazine){
            if(freq[ch-'a']!=0) freq[ch-'a']--;
        }
        return all_of(freq.begin(),freq.end(),[](int x)
            {
                return x==0;
            }
        );
    }
};
