// Approach 1 : I used reverse logic to get the output array , which worked on some testcases but stopped on those whoes output depended on the inital or previous 
// position
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> result(n,0);

        result[n-1]=n;

        for(int i=n-2;i>0;i--){
            if(A[i+1]==B[i+1]){
                result[i]=result[i+1]-1;
            }
            else{
                int output=result[i+1]-2;
                result[i]=output;
                i--;
            }
        }
        if(A[0]==B[0]) result[0]=1;
        return result;
    }
};

// Approach 2 : I used an unorderd_map to count the frequencies of the arrays 
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> result(n);
        unordered_map<int,int> mp;

        int common=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if(mp[A[i]]==2)common++;
            mp[B[i]]++;
            if(mp[B[i]]==2)common++;

            result[i]=common; 
        }
        return result;
        
    }
};
