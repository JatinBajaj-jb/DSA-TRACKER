// Approach 1 : I tried to solve the question using substr method
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();

        for(int left=0;left<=n-m;left++){
            if(needle==haystack.substr(left,m)) return left;
        }
        return -1;
    }
};
// Approach 2 : I solved the problem using O(1) space complexity  and O(n*m) time complexity
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        for(int i=0;i<n-m;i++){
            int j=0;
            while(j<m && haystack[i+j]==needle[j]) j++;

            if(j==m) return i;
        }
        return -1;
        
    }
};
// Approach 3 : I used KMP algorithm to solve the problem 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        vector<int> lps(m,0);
        int len=0;
        int i=1;

        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int h=0;
        int p=0;

        while(h<n){
            if(haystack[h]==needle[p]){
                h++;
                p++;
            }
            if(p==m) return h-p;
            else if(h<n && haystack[h]!=needle[p]){
                if(p!=0){
                    p=lps[p-1];
                }
                else{
                    h++;
                }
            }
        }
        return -1;
    }
};



