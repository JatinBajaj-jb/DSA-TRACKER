class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
        int ans=-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            int val=guess(mid);
            if(val==-1){
                right=mid-1;
            }
            else if(val==1){
                left=mid+1;
            }
            else{
                ans= mid;
                break;
            }
        }
        return ans;
    }
};
