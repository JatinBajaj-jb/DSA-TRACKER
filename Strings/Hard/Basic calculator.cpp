// Approach 1: i used a recursive approach , honestly it was easier than i thought but i has a large time complexity;\
class Solution {
private:
    int solve(string s,int& i){
        int number=0;
        int ans=0;
        int sign=1;
        for(i;i<s.length();i++){
            if(s[i]==' '){
                continue;
            }
            else if(s[i]=='-'){
                ans+=sign*number;
                number=0;
                sign=-1;
            }
            else if(s[i]=='+'){
                ans+=sign*number;
                number=0;
                sign=1;
            }
            else if(isdigit(s[i])){
                number=number*10+(s[i]-'0');
            }
            else if(s[i]=='('){
                i++;
                number=solve(s,i);
            }
            else if(s[i]==')'){
                ans+=sign*number;
                return ans;
            }   
        }       
        ans+=sign*number;
        return ans;
    }
public:
    int calculate(string s) {
        int i=0;
        int result=solve(s,i);
        return result;
    }
};
