// Approach 1 : I used reversing technique on the array 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int pivotIndx=k%n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+pivotIndx);
        reverse(nums.begin()+pivotIndx,nums.end());
        return;
    }
};
