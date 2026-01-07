// Approach 1 : I tried to solve the question by using swap method 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int j=i+1;
                while(j<n){
                    swap(nums[j],nums[j-1]);
                    j++;
                }
            }
        }
        return ;
    }
};
// Approach 2 : I tried two pointer approach where we place all the non zero numbers to the beginning 
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
