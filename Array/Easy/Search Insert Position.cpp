// Approach , I did basic binary search (O(nlogn)) and i did left<=right to make sure the correct last position is checked 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=-1;
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]>target){
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                return mid;
            }
        }

        return left;        
    }
};
