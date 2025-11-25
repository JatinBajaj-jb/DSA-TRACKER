// Approach 1 : I used modulo approach 
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int level=1;
        set<int> st;
        int modulo=1;
        while(1){
            modulo=modulo % k;
            if(modulo==0) return level;
            if(st.find(modulo)!=st.end()){
                return -1;
            }else{
                st.insert(modulo);
            }
            modulo=modulo*10+1;
            level++;
        }
        return -1;
    }
};
// Approach 2 : same approach with a slightly better looping conditon ie from 0 to k-1;
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int level=1;
        int modulo=1;
        for(int i=0;i<k;i++){
            modulo=modulo % k;
            if(modulo==0) return level;
            modulo=modulo*10+1;
            level++;
        }
        return -1;
    }
};
