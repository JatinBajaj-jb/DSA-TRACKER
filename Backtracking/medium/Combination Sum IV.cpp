//Approach -1:
// I have taken the general for loop backtracking approach , it is a dp problem but i tried to solved it with general backtracking <3

class Solution {
    int n;
    int ans;
private:
    void find(vector<int> &nums,int target,vector<int> &temp,int sum){
        if(sum>=target){
            if(sum==target){
                ans++;
            }
            return;
        }
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
            sum+=nums[i];
            find(nums,target,temp,sum);
            temp.pop_back();
            sum-=nums[i];
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> temp;
        find(nums,target,temp,0);
        temp.pop_back();
        return ans;
        
    }
};

//Approach -2:
//I have tried another method where it is like dp , we take and not take the nums[indx] element <3

class Solution {
    int n;
private:
    int solve(vector<int>& nums, int target,int indx){
        if(target==0){
            return 1;
        }
        if(indx>=n || target<0){
            return 0;
        }
        int taken=solve(nums,target-nums[indx],0);
        int not_taken=solve(nums,target,indx+1);

        return taken+not_taken;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        int ans= solve(nums,target,0);
        return ans;
    }
};
