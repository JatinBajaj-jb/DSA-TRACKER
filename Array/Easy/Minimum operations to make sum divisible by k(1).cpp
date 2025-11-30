// Approach 1 : I calculated the sum and did a check on it 
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result=0;
        long long sum=accumulate(nums.begin(),nums.end(),0);
        while(sum%k!=0){
            sum--;
            result++;
        }
        return result;
        
    }
};
