// Approach : I truncated the result string to the length which was common
class Solution {
private:
    string prefix(string s,string s1){
        int n=s.length();
        int m=s1.length();
        int j=0,i=0;
        for(i=0;i<n;i++){
            if(j>=m) break;
            if(s[i]==s1[j]){
                j++;
            }
            else{
                break;

            }
        }
        return s.substr(0,j);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return strs[0];

        string result=strs[0];
        for(int i=1;i<n;i++){
            result=prefix(result,strs[i]);
        }
        return result;
        
    }
};
