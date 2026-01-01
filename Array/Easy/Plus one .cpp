// Approach 1 : brute forced my way through , i used another variable carry 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+carry;
            if(digits[i]!=9){
                if(i!=n-1) digits[i]=sum;
                else digits[i]=sum+1;
                carry=0;
                break;
            }
            else{
                digits[i]=0;
                carry=1;

            }
        }
        if(carry==0)return digits;
        else{
            vector<int> result(n+1,1);
            for(int i=0;i<n;i++){
                result[i+1]=digits[i];
            }
            return result;
        }
    }
};

// Approach 2 : I learned and simplified the code 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            
            if(digits[i]!=9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i]=0;
            }
        }    
        digits.insert(digits.begin(),1);
        return digits;
    }
};
