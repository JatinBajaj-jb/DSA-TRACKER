// Approach 1 : I used set to find the duplicate and the difference of sum to find the missing 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        int sumn=0;
        int sumcurr=0;
        int dp=-1;
        set<int> st;
        for(int i=0;i<n;i++){
            sumn+=i+1;
            sumcurr+=nums[i];
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
            }
            else{
                dp=nums[i];
                result.push_back(nums[i]);
            }
        }
        result.push_back(sumn-sumcurr+dp);
        return result;
    }
};

// Approach 2 : I used bit manipulation 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        for(int& num:nums){
            xor1^=num;
        }
        for(int i=1;i<=n;i++){
            xor1^=i;
        }
        int separator=xor1&-xor1;
        int xor_a=0;
        int xor_b=0;
        for(int& num:nums){
            if(num & separator){
                xor_a^=num;
            }
            else{
                xor_b^=num;
            }
        }
        for(int i=1;i<=n;i++){
            if( i & separator){
                xor_a^=i;
            }
            else{
                xor_b^=i;
            }
        }
        for(int& num:nums){
            if(num==xor_a) return {xor_a,xor_b};
        }
        return {xor_b,xor_a};  
    }
};
