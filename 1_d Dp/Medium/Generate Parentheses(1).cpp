// Approach :
class Solution {
private:
    void solve(vector<string>& result,int n1,int n2,string temp){
        if(n1==0 && n2==0){
            result.push_back(temp);
            return;
        }
        if(n1>0){
            solve(result,n1-1,n2+1,temp+'(');
        }
        if(n2>0){
            solve(result,n1,n2-1,temp+')');
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp="(";
        solve(result,n-1,1,temp);
        return result;
    }
};

// Approach 2 : I passes temp by refrence 
class Solution {
private:
    void solve(vector<string>& result,int n1,int n2,string& temp){
        if(n1==0 && n2==0){
            result.push_back(temp);
            return;
        }
        if(n1>0){
            temp.push_back('(');
            solve(result,n1-1,n2+1,temp);
            temp.pop_back();
        }
        if(n2>0){
            temp.push_back(')');
            solve(result,n1,n2-1,temp);
            temp.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp="(";
        solve(result,n-1,1,temp);
        return result;
    }
};
