class Solution {
    int n;
private:
    void find(vector<string> &ans,string &digits,unordered_map<char,string> &mp,string &temp1,int indx){
        if(indx==n){
            ans.push_back(temp1);
            return;
        }
        string temp = mp[digits[indx]];
        for(int i=0;i<temp.size();i++){
            temp1+=temp[i];
            find(ans,digits,mp,temp1,indx+1);
            temp1.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        n=digits.length();
        vector<string> ans;
        string temp1;
        if(n==0){
            return ans;
        }
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        find(ans,digits,mp,temp1,0);
        return ans;
    }
};
