// Attempt 1 : I tried to solve the question by finding the pivot and then operating on the array 
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int pivot =-1;
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[n-1]) left=mid+1;
            else right=mid;
        }
        pivot=right;


        for(int i=right;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false; 
        }
        
        for(int i=0;i<right-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
};
// Approach 1 : I counted the number of drops in the array , 0 drops=> sorted array or equal array , 1 drop=> rotated array ,>1 drops=> false output 
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]) count++;
        }
        return count<=1;
    }
};
