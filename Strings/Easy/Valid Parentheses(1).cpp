class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            char curr=s[i];
            if(curr=='(' ||curr=='{' || curr=='[') st.push(curr);
            else {
                if(st.empty()) return false;
                if((curr==')' && st.top()=='(') || (curr=='}' && st.top()=='{') || (curr==']' && st.top()=='[')){
                    st.pop();
                }
                else{
                    st.push(curr);
                }
            }
        }
        return st.empty();
    }
};
