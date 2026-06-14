// Approach 1 :I used set to track the loop
class Solution {
private:
    int get(int n){
        int result=0;
        while(n>0){
            result+=pow(n%10,2);
            n/=10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        set<int> seen;
        int curr=get(n);
        while(seen.find(curr)==seen.end()){
            seen.insert(curr);
            if(curr==1) return true;
            curr=get(curr);
        }
        return false;
        
    }
};
