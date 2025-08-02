// Approach : i first tried to do the question with sliding window approach , it worked for a while and passed half of the cases 
//  but it was not sufficient ; then i used the approach of kadane approach to the soltuion , overall a good question to improve dsa skills;
class Solution {
public:
    int largestVariance(string s) {
        set<char> st;
        int result=INT_MIN;
        bool isback=false;
        for(char val:s){
            st.insert(val);
        }
        for(char val1:st){
            for(char val2:st){
                if(val1==val2){
                    continue;
                }
                int f1=0;
                int f2=0;
                for(char ch:s){
                    if(ch==val1){
                        f1++;
                    }
                    if(ch==val2){
                        f2++;
                    }
                    if(f2>f1){
                        f2==0;
                        f1==0;
                        isback=true;
                    }
                    if(f2>0){
                        result=max(result,f1-f2);
                        isback=false;
                    }
                    else if(isback){
                        result=max(result,f1-1);
                    }

                }
            }
        }
        return result==INT_MIN?0:result;
    }
};
