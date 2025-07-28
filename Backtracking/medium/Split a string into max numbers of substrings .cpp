class Solution {
private:
    void solve(string s,int j,unordered_set<string>& st,int count,int& maxcount){
        if(j==s.length()){
            maxcount=max(maxcount,count);
        }
        if(j>s.length()){
            return ;
        }
        for(int i=j;i<s.length();i++){
            if(maxcount!=0 && maxcount>=count+(s.length()-j)){
                continue;
            }   
            string curr=s.substr(j,i-j+1);
            if(st.find(curr)==st.end()){
                st.insert(curr);
                solve(s,i+1,st,count+1,maxcount);
                st.erase(curr);
            }
        }
    }

public:
    int maxUniqueSplit(string s) {
        string curr;
        unordered_set<string> st;
        int maxcount=0;
        solve(s,0,st,0,maxcount);
        return maxcount;
    }
};
