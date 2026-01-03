// Approach 1 : I used strealine along with a function to remove all the extra spaces of the string 
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isfirst=true;
        string curr="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ') isfirst=false;
            if(s[i]==' ' && isfirst) continue;
            else if(i>0 && s[i]==' '&& s[i-1]==' ') continue;
            curr+=s[i];
        }

        string temp;
        stringstream ss(curr);
        int count=0;
        while(getline(ss,temp,' ')){
            count=temp.length();
        }
        return count;
    }
};
// Approach 2 : I used another method in which i started from the end and counted the length of the last substring 
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int end=s.length()-1;

        while(end>=0 && s[end]==' ') end--;
        while(end>=0 && s[end]!=' '){
            end--;
            count++;
        }
        return count;
    }
};
