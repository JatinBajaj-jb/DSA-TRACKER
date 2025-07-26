// Approach 1 : I just used the standard backtracking approach 
class Solution {
private: 
    void solve(vector<string> &ans,string sentence,string s,unordered_set<string> &st,int i){
        if(i>=s.length()){
            ans.push_back(sentence);
            return;
        }
        for(int j=i;j<s.length();j++){
            string curr=s.substr(i,j-i+1);
            if(st.count(curr)){
                string newsentence=sentence.empty()?curr:sentence+" "+curr;
                solve(ans,newsentence,s,st,j+1);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string sentence="";
        unordered_set<string> st;
        for(auto val: wordDict){
            st.insert(val);
        }
        vector<string> ans;
        solve(ans,sentence,s,st,0);
        return ans;
    }
};
// Approach 2: used memorzing ;
class Solution {
private:
    vector<string> solve(string s,unordered_set<string> &st){
        if(s.empty()){
            return {""};
        }
        vector<string> ans;
        for(int l=1;l<=s.length();l++){
            string curr=s.substr(0,l);
            if(st.count(curr)){
                string word=s.substr(l);
                vector<string> remaining=solve(word,st);
                for(string &w:remaining){
                    string to_add=curr+(w.empty()?"":" ")+w;
                    ans.push_back(to_add);
                }
            }

        }
        return ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto val: wordDict){
            st.insert(val);
        }
        
        return solve(s,st);
    }
};
