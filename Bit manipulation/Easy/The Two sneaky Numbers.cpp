// Approach 1 : I just used set to track the number count:
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        set<int> st;
        for(int i=0;i<n;i++){
            if(st.find(nums[i])!=st.end()){
                result.push_back(nums[i]);
            }
            else{
                st.insert(nums[i]);
            }
        }
        return result;
    }
};
// Approach 2 : I used xor technique to find the seperator using __builtin_ctz() and then group the numbers and took another xor ;
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int zero=0;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            zero=zero^nums[i];
        }
        for(int i=0;i<=nums.size()-3;i++){
            zero=zero^i;
        }
        int trailz=__builtin_ctz(zero);
        int sep=1<<trailz;
        int g1=0;
        int g2=0;

        for(int i=0;i<nums.size();i++){
            if(i<=nums.size()-3){
                if((i&sep)==0){
                    g1^=i;
                }
                else{
                    g2^=i;
                }
            }
            if((nums[i]&sep)==0){
                g1^=nums[i];
            }
            else{
                g2^=nums[i];
            }
        }
        result.push_back(g1);
        result.push_back(g2);
        return result;
    }
};
