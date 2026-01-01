// Approach 1 : I used two for loops to get the answer , resulting in tle
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(temp[j]>temp[i]){
                    result[i]=count;
                    break;
                }
                count++;
            }
        }
        return result; 
    }
};
// Approach 2 : I used monotonic stack to find the result vector
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int> st;
        vector<int> result(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[i]>=temp[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                result[i]=st.top()-i;
            }
            st.push(i);
        }
        return result; 
    }
};
