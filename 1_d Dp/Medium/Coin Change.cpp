// Approach 1 : I used dp+memorization to get the desired output 
class Solution {
private:    
    bool solve(vector<int>& coins,int indx,int amount,int& result,int steps){
        if(amount==0) return true;
        else if(amount<0) return false;
        if(indx>=coins.size()) return false;

        int curr=coins[indx];

        for(int i=0;i<coins.size();i++){
            if(solve(coins,indx+1,amount-curr,result,steps+1)){
                result=min(result,steps+1);
            }
        }
        return true;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0) return -1;

        int result=INT_MAX;

        solve(coins,0,amount,result,0);

        return result;
    }
};
