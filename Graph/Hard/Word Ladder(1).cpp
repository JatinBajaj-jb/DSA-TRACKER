// Approach : I used bfs to get to the target word , and made a alphabet array 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<char> alp(26);
        for(int i=0;i<26;i++){
            alp[i]='a'+i;
        }
        unordered_set<string> st;
        for(auto& s:wordList){
            st.insert(s);
        }
        int result=0;
        queue<string> pq;
        pq.push(beginWord);
        st.erase(beginWord);
        while(!pq.empty()){
            int N=pq.size();
            while(N--){
                string curr=pq.front();
                if(curr==endWord) return result+1; 
                pq.pop();
                for(int i=0;i<curr.length();i++){
                    char ch=curr[i];
                    char temp=ch;
                    for(char val:alp){
                        if(val!=ch){
                            curr[i]=val;
                            if(st.find(curr)!=st.end()){
                                pq.push(curr);
                                st.erase(curr);
                            }
                        }
                    }
                    curr[i]=temp;
                }
            }
            result++;
        }
        return 0;
    }
};
