// Approach 1 : I used to find the pivot indx . swap it with the next highest element and then reverse the rest of the string 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot_indx=-1;
        int n=nums.size();

        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                pivot_indx=i-1;
                break;
            }
        }
        if(pivot_indx!=-1){
            for(int i=n-1;i>pivot_indx;i--){
                if(nums[i]>nums[pivot_indx]){
                    swap(nums[i],nums[pivot_indx]);
                    break;
                }

            }
        }
        reverse(nums.begin()+pivot_indx+1,nums.end());
        return;
    }
};
