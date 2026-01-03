// Approach 1: I tried to find the brute force soltution 
class Solution {
private:
    string toDelete(string curr,string word){
        string answer="";
        string temp;
        stringstream ss(word);
        while(getline(ss,temp,'/')){
            if(temp!=curr){
                answer+="/";
                answer+=temp;
            }
        }
        return answer;

    }
    string removeSlash(string path){
        string curr="";
        int n=path.length();
        for(int i=1;i<n;i++){
            if(i>0 && path[i]=='/' && path[i-1]=='/') continue;
            curr+=path[i];
        }
        return curr;
    }
public:
    string simplifyPath(string path) {
        int n=path.length();
        string curr=removeSlash(path);
        string temp;
        stringstream ss(curr);
        string result="";
        string prev="0";
        string secondPrev="0";
        while(getline(ss,temp,'/')){

            if(temp==".." && prev!="0"){
                result=toDelete(prev,result);
                prev=secondPrev;
                continue;
            }
            else if(temp==".." && prev=="0"){
                continue;
            }
            else if(temp==".") continue;
            result+='/';
            result+=temp;
            secondPrev=prev;
            prev=temp;
        
        }
        return "/"+removeSlash(result);
    }
};
// Approach 2 : I used stack 
class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string> st;
        string temp;
        stringstream ss(path);
        while(getline(ss,temp,'/')){
            if(temp=="" || temp==".") continue;
            else if(temp==".." && !st.empty()){
                st.pop();
                continue;
            }
            else if(temp==".." && st.empty()) continue;
            st.push(temp);
        }
        string result="";
        while(!st.empty()){
            string curr=st.top();
            result="/"+curr+result;
            st.pop();
        }
        return result==""?"/":result; 
    }
};

// Approach 3 : I got the soltution in optimal time 
class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        vector<string> st;
        string temp;
        stringstream ss(path);
        while(getline(ss,temp,'/')){
            if(temp=="" || temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop_back();
                continue;
            }
            st.push_back(temp);
        }

        string result="";
        for(auto& vec:st){
            result+="/"+vec;
        }
        return result==""?"/":result; 
    }
};
