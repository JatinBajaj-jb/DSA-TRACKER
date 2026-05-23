// Approach 1 : I use two pointer approach to get the result 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1;
        int p2=n-1;

        int curr=n+m-1;

        while(p1>=0 && p2>=0){
            if(nums1[p1]>nums2[p2]){
                nums1[curr--]=nums1[p1--];
            }
            else nums1[curr--]=nums2[p2--];
        }
        while(p2>=0){
            nums1[curr--]=nums2[p2--];
        }
        return;        
    }
};
