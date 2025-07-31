// Approach 1 : I just used backtracking along with a lot of patience, was comparitively on a harder side 
class Solution {
private:
    void solve(string& s,vector<string>& result,string curr,int i,int count){
        int remcharac=s.size()-i;
        int remcount=4-count;
        if(remcharac<remcount || remcharac>remcount*3){
            return;
        }
        if(i>s.size() || count>4){
            return;
        }
        if(count==4 &&i==s.size()){
            result.push_back(curr);
            return;
        }
        int j;
        for(j=1;j<=3;j++){
            bool b=false;
            if(i+j>s.size()){
                break;
            }
            string temp=s.substr(i,j);
            int a=stoi(temp);
            if(temp.size()>1 && temp[0]=='0'){
                b=false;
            }
            else if(a>=0 && a<=255){
                b=true;
            }
            if(b){            
                solve(s,result,curr.empty()?curr+temp:curr+"."+temp,i+j,count+1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string curr;
        solve(s,result,curr,0,0);
        return result;
    }
};
