// Approach : I just used the simple two pointer approach with a set to find duplicates:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int indx1=0;
        int indx2=0;
        set<int> st;
        while(indx2<nums.size()){
            if(st.find(nums[indx2])==st.end()){
                st.insert(nums[indx2]);
                nums[indx1++]=nums[indx2++];
            }
            else{
                indx2++;
            }
        }
        return indx1;

    }
};
