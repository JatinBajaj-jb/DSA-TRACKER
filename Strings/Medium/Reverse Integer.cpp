// Approach 1 : I have multiple checks for the overflow condition 
class Solution {
public:
    int reverse(int x) {
        int rev=0;

        while(x!=0){
            int digit=x%10;
            x/=10;
     
            if(rev>INT_MAX/10 ||(rev==INT_MAX && digit>7)) return 0;
            if(rev<INT_MIN/10 ||(rev==INT_MIN && digit<-8)) return 0;        
            rev=rev*10+digit;
        }
        return rev;
    }
};
