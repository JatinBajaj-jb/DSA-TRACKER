class Solution {
private:
    bool check(int target,int h,vector<int>& piles){
        int hours=0;
        int left=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]+target-1)/target;
        }
        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=-1;
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<right){
            int mid=left+(right-left)/2;
            if(check(mid,h,piles)){
                // ans=mid;
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
