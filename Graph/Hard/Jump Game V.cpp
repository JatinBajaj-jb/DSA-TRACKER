// Approach 1 : I tried dp +dfs+memorization
class Solution {
private:
    int dfs(vector<int>& arr,vector<int>& memo,int i,int d){
        if(i>=arr.size() || i<0) return 0;

        if(memo[i]!=-1) return memo[i];

        int p1=1;
        for(int indx=i+1;indx<=i+d;indx++){
            if(indx>=arr.size()) break;

            else if(arr[indx]>=arr[i]) break;
            p1=max(p1,1+dfs(arr,memo,indx,d));
        }
        int p2=1;
        for(int indx=i-1;indx>=i-d;indx--){
            if(indx<0) break;
            else if(arr[indx]>=arr[i]) break;
            p2=max(p2,1+dfs(arr,memo,indx,d));
        }
        return memo[i]=max(p1,p2);
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int result=INT_MIN;

        vector<int> memo(n,-1);

        for(int i=0;i<n;i++){
            result=max(result,dfs(arr,memo,i,d));
        }
        return result;
    }
};
