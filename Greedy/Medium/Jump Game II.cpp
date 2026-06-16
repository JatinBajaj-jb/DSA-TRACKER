// Approach 1 : Using BFS Traversal
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        queue<int> que;
        que.push(0);
        vector<bool> visited(n,0);
        visited[0]=true;
        int jumps=0;

        while(!que.empty()){
            int N=que.size();
            while(N--){
                int top=que.front();
                que.pop();
                if(top==n-1) return jumps;

                for(int i=1;i<=nums[top];i++){
                    if(top+i<n && !visited[top+i]){
                        que.push(top+i);
                        visited[top+i]=true;
                    }
                }
            }
            jumps++;
        }
        return jumps; 
    }
};
// Approach 2 : I used greedy 
class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0;
        int currEnd=0;
        int jumps=0;

        for(int indx=0;indx<nums.size()-1;indx++){
            farthest=max(farthest,indx+nums[indx]);

            if(indx==currEnd){
                jumps++;
                currEnd=farthest;
            }
        }
        return jumps;
    }
};
