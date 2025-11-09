// Approach : I used sliding window approach where i incremented the left pointer everytime i got a recurring element and right point only when there wasnt a recurring 
// element 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==" ") return 1;
        int l=0;
        int r=0;
        int result=0;
        set<int> st;
        while(r<s.length()){
            if(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;   
            }
            else{
                st.insert(s[r]);
                result=max(result,r-l+1);
                r++;
            }
        }
        return result;
    }
};
