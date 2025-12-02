// Approach 1 :
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n+1,-1);
        for(int i=0;i<n;i++){
            temp[nums[i]]=0;
        }
        vector<int> result;
        for(int i=1;i<=n;i++){
            if(temp[i]==-1){
                result.push_back(i);
            }
        }
        return result;
    }
};
// Approach 2 : I solved the problem in linear space complexity 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int indx=abs(nums[i])-1;
            nums[indx]=-1*abs(nums[indx]);
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                result.push_back(i+1);
            }
        }
        return result;
    }
};
