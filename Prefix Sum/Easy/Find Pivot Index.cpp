// Approach 1 : I used prefix sum from left to right and then from right to left and equated the two vectors to find the result
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> leftMost(n,0);
        vector<int> rightMost(n,0);

        for(int i=1;i<n;i++){
            leftMost[i]=leftMost[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightMost[i]=rightMost[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++){
            if(leftMost[i]==rightMost[i]) return i;
        }
        return -1;
        
    }
};
