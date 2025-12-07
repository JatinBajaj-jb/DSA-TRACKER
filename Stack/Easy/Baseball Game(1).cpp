// Approach 1 : I used stack with basic functions 
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto& s:operations){
            if(s=="C"){
                st.pop();
            }
            else if(s=="D"){
                st.push(2* st.top());
            }
            else if(s=="+"){
                int c1=st.top();
                st.pop();
                int c2=st.top();
                st.push(c1);
                st.push(c1+c2);
            }
            else{
                int c1=stoi(s);
                st.push(c1);
            }
        }
        int result=0;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};

// Approach 2 : I calculated the result in one flow instead of a external loop 
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result=0;
        stack<int> st;
        for(auto& s:operations){
            if(s=="C"){
                result-=st.top();
                st.pop();
                continue;
            }
            else if(s=="D"){
                st.push(2* st.top());
            }
            else if(s=="+"){
                int c1=st.top();
                st.pop();
                int c2=st.top();
                st.push(c1);
                st.push(c1+c2);
            }
            else{
                int c1=stoi(s);
                st.push(c1);
            }
            if(!st.empty()) result+=st.top();
        } 
        return result;
    }
};

