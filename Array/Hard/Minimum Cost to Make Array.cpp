// Approach 1 : I just used the simple brute force approach where i got O(N^2) time complexity;
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long suma=INT_MAX;
        long long n=nums.size();
        for(int i=0;i<n;i++){
            long long total=0;
            long long select=nums[i];
            for(int j=0;j<n;j++){
                long long curr=nums[j];
                if(i==j){
                    continue;
                }
                if(curr>select){
                    total+=(curr-select)*cost[j];
                }
                if(curr<select){
                    total+=(select-curr)*cost[j];
                }
            }
            suma=min(total,suma);
        }
        return suma;
    }
};
// Approach 2 : I used binary search , one thing being that we have to check if the f(x) is convex , if it is we use mid+1 approach "
class Solution {
typedef long long ll;
private:
    ll check(vector<int>& nums, vector<int>& cost,ll mid){
        ll total=0;
        for(int i=0;i<nums.size();i++){
            total+=abs(nums[i]-mid)*cost[i];
        }
        return total;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll result=LLONG_MAX;
        ll left=*min_element(nums.begin(),nums.end());
        ll right=*max_element(nums.begin(),nums.end());
        while(left<=right){
            ll mid=left+(right-left)/2;

            ll c1=check(nums,cost,mid);
            ll c2=check(nums,cost,mid+1);

            result=min({result,c1,c2});
            if(c1>c2){
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        return result;
    }
};
// Approach 2 : I used weighted median approach 
class Solution {
typedef long long ll;
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll result=0;
        int n=nums.size();
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i]={nums[i],cost[i]};
        }
        sort(begin(arr),end(arr));
        ll total=0;
        for(auto p:arr){
            total+=p.second;
        }
        ll cumulate=0;
        ll select=0;
        for(auto p:arr){
            cumulate+=p.second;
            if(cumulate*2>=total){
                select=p.first;
                break;
            }
        }
        for(int i=0;i<n;i++){
            result+=(ll)abs(select-nums[i])*cost[i];
        }
        return result;
    }
};
