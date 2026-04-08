// Approach 1 : I used a ready made algorithm to find the solution , the problem required me to think more optimally as well as pattern recognition was tested 
class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        int n=s.length();
        if(numRows==1) return s;
        int increment=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j+=increment){
                result+=s[j];
                int diag=j+increment-2*i;                
                if(i!=0 && i!=numRows-1 && diag<n){
                    result+=s[diag];
                }
            }
        }
        return result;        
    }
};
