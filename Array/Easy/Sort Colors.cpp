// Approach 1 : I did the dnf algorithm
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int indx=0;
        for(int x:nums){
            if(x!=0) nums[indx++]=x;
        }
        while(indx<n){
            nums[indx++]=0;
        }
        return;
    }
};
