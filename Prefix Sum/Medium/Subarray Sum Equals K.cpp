// Approach 1 : I tried to solve the question with the brute force solution but it was not successful due to the negative sum 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
        
    }
};

// Approach 2 : Solved the problem using prefix sum structure , 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]++;

        int curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];

            if(mp.find(curr-k)!=mp.end()){
                count+=mp[curr-k];
            }
            mp[curr]++;
        }
        return count;        
    }
};
