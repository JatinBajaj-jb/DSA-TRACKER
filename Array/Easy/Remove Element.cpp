// Approach 1 : I did a simple two pointer approach 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result=0;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]!=val){
                nums[left++]=nums[right];
                result++;
            }
        }
        return result;
    }
};
