// Approach 1 : I tried to solve it using brute force greedy with O(n2) time complexity 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=gas[i]-cost[i];
        }
        for(int i=0;i<n;i++){
            if(diff[i]<0) continue;
            int sum=0;
            bool reachable=true;

            for(int j=0;j<n;j++){
                sum+=diff[(j+i)%n];
                if(sum<0) reachable=false ;
            }
            if(reachable) return i;
        }
        return -1;
    }
};

// Approach 2 : I solve it using greedy with O(n) complexity 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int tank=0;
        int start=0;

        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            tank+=diff;

            if(tank<0){
                start=i+1;
                tank=0;
            }
        }
        return total>=0?start:-1;
        
    }
};
