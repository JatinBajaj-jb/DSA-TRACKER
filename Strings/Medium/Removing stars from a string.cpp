// Approach 1 : i just used iterative approach 
class Solution {
public:
    string removeStars(string s) {
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='*' && !result.empty()){
                result.pop_back();
                continue;
            }
            result+=s[i];
        }
        return result;
    }
};
// Approach 2: I used stack 
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string result="";
        for(char val:s){
            if(val=='*' && !st.empty()){
                st.pop();
                continue;
            }
            st.push(val);
        }
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};
