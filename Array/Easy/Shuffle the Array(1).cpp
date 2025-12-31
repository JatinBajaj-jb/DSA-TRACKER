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
// Attempt 2 : solved this question with almost the same method
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int mid=n-1;
        vector<int> result(2*n,0);
        int indx1=0;
        int indx2=n;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                result[i]=nums[indx1++];
            }
            else{
                result[i]=nums[indx2++];
            }
        }
        return result;
    }
};
