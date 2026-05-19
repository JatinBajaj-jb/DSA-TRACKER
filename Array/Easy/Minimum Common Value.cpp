// Approach 1 : I used two pointer approach , one each for both array and then found the first common element 
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int result=-1;

        int indx1=0,indx2=0;

        while(indx1<nums1.size() && indx2<nums2.size()){
            if(nums1[indx1]==nums2[indx2]){
                result=nums1[indx1];
                break;
            }
            else if(nums1[indx1]<nums2[indx2]){
                indx1++;
            }
            else indx2++;
        }
        return result;
    }
};
