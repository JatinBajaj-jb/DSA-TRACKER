//Approach : I tried to use backtracking , one thing this problem teach me was isaplha() function 
class Solution {
private:
    void solve(string s,vector<string>& result,string curr,int indx,int n){
        if(indx==n){            
            result.push_back(curr);
            return;
        }
        if(indx>n){
            return;
        }
        char t=s[indx];
        if(isalpha(t)){
            t=tolower(t);
            solve(s,result,curr+t,indx+1,n);
            t=toupper(t);
            solve(s,result,curr+t,indx+1,n);
        }
        else{
            solve(s,result,curr+t,indx+1,n);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.length();
        vector<string> result;
        string curr="";
        solve(s,result,curr,0,n);
        return result;
        
    }
};
