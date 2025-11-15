// Approach : I used bfs 
class Solution {
private:
    void fillne(queue<string>& q,string curr,unordered_set<string>&st){
        for(int i=0;i<4;i++){
            char ch=curr[i];

            char inc =ch=='9'?'0':ch+1;
            curr[i]=inc;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }
            char dec=ch=='0'?'9':ch-1;
            curr[i]=dec;
            if(st.find(curr)==st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i]=ch;
        }
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(),deadends.end());
        queue<string> q;
        if(st.find("0000")!=st.end()) return -1;
        q.push("0000");

        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                
                if(curr==target){
                    return level;
                }
                fillne(q,curr,st);
            }
            level++;
        }
        return -1;
    }
};
