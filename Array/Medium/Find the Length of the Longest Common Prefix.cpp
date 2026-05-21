// Approach 1 : I tried to brute force my way through the solution but it ended up tle 
class Solution {
private:
    int find(int x ,int y){
        string strX=to_string(x);
        string strY=to_string(y);
        int output=0;
        int n=min(strX.length(),strY.length());
        for(int i=0;i<n;i++){
            if(strX[i]==strY[i]){
                output++;
            }
            else {break;}
        }
        return output;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxl=INT_MIN;
        for(int x:arr1){
            for(int y:arr2){
                maxl=max(maxl,find(x,y));
            }
        }
        return maxl;
    }
};
// Approach 2 : I used unordered_set to get the result;
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int result=0;

        unordered_set<string> st;
        for(int num:arr1){
            string x=to_string(num);
            string curr="";
            for(int i=0;i<x.length();i++){
                curr+=x[i];
                if(!st.count(curr)) st.insert(curr);
            }
        }
        for(int num:arr2){
            string y=to_string(num);
            while(!y.empty()){
                if(st.count(y)){
                    result=max(result,(int)y.length());
                }
                y.pop_back();
            }
        }
        return result;
        
    }
};




  
