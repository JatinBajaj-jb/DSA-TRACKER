// Approach 1 : I solve the question by taking a hash map of int and a vector of int to store the indices and got the frequency by taking the length of the indices 
class Solution {
private:
    int solve(int i,int j,int k){
        return abs(i-j)+abs(j-k)+abs(k-i);
    }
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int result=INT_MAX;
        for(auto& it :mp){
            if (it.second.size()==3){
                result=min(result,solve(it.second[0],it.second[1],it.second[2]));
            
            }
        }
        return (result==INT_MAX?-1:result);
    }
};
