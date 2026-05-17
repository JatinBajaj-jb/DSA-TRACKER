// Approach 1 : I used bfs Solution to get the result , since the solution dependend on the previous state , we couldn't use dp 
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> que;
        vector<int> visited(n,0);
        que.push(start);
        visited[start]=1;

        while(!que.empty()){
            int N=que.size();

            while(N--){
                int currIndx=que.front();
                que.pop();
                if(arr[currIndx]==0) return true;

                int currVal=arr[currIndx];
                int leftVal=currIndx-currVal;
                int rightVal=currIndx+currVal;

                if(leftVal>=0 && leftVal<n && !visited[leftVal]){
                    que.push(leftVal);
                    visited[leftVal]=1;
                }
                if(rightVal>=0 && rightVal<n && !visited[rightVal]){
                    que.push(rightVal);
                    visited[rightVal]=1;
                }
            }
        }
        return false;
    }
};
