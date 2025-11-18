class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int mid=n;
        vector<int> result;
        for(int i=0;i<mid;i++){
            if(mid>=2*n) break;
            result.push_back(nums[i]);
            result.push_back(nums[mid++]);
        }
        return result;
    }
};
