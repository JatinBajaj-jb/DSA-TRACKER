class Solution {
private:
    void bs(int left,int right,int& indx,int target,vector<int>& nums){
        if(left>right){
            return;
        }
        int mid=left+(right-left)/2;
        if(nums[mid]>target){
            bs(left,mid-1,indx,target,nums);
        }
        else if(nums[mid]<target){
            bs(mid+1,right,indx,target,nums);
        }
        else if(target==nums[mid]){
            indx=mid;
        }
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        int indx=-1;
        int pivot=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums.size()>1 && nums[i+1]<nums[i]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            bs(0,nums.size()-1,indx,target,nums);
        }
        else{
            if(target>=nums[0]){
                bs(0,pivot,indx,target,nums);
            }
            else if(target<nums[0]){
                bs(pivot+1,nums.size()-1,indx,target,nums);
            }
        }
        return indx;
    }
};