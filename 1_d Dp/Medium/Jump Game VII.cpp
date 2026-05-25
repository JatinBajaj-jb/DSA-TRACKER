// Approach 1 : I tried to solve the problem using dp and visited array for a sort of memorization part (tle)
class Solution {
private:
    bool dp(const string& s ,vector<int>& visited,int minJump ,int maxJump,int indx){
        if(indx>=s.length()) return false;
        if(indx==s.length()-1) return true;

        visited[indx]=1;
        for(int i=minJump;i<=maxJump;i++){
            if(indx+i>=s.length()) break;
            if(!visited[indx+i] && s[indx+i]=='0'){
                if(dp(s,visited,minJump,maxJump,indx+i)) return true;
            }
        }
        return false;


    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<int>visited(n,0);
        bool result=dp(s,visited,minJump,maxJump,0);
        return result;
    }
};

// Approach 2 : I used the bottom up approach 
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();

        vector<int> visited(n,0);

        visited[n-1]=true;
        for(int i=n-1;i>=0;i--){
            if(!visited[i]) continue;
            for(int jump=minJump;jump<=maxJump;jump++){
                int j=i-jump;
                if(j<0) break;
                if(s[j]=='0' && !visited[j]){
                    visited[j]=true;
                }
            }
        }
        return visited[0];
        
    }
};
// Approach 3 : I tried to solve the question using furthest pointer approach  
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();

        vector<int> visited(n,0);

        int furthest=0;

        visited[0]=1;

        for(int i=0;i<n;i++){
            if(!visited[i]) continue;

            int start=max(i+minJump,furthest);
            int end=min(i+maxJump,n-1);

            for(int jump=start;jump<=end;jump++){
                if(s[jump]=='0' && !visited[jump]){
                    visited[jump]=1;
                }
            }
            furthest=end+1;

            if(visited[n-1]) return true;
        }
        return false;
    }
};

// Approach 2 : I tried to used sliding window method 
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();

        vector<int> reachable(n,0);
        reachable[0]=1;
        int count=0;
        for(int i=1;i<n;i++){

            if(i-minJump>=0){
                if(reachable[i-minJump]) count++;
            }
            if(i-maxJump-1>=0){
                if(reachable[i-maxJump-1]) count--;
            }

            if(count>0 && s[i]=='0'){
                reachable[i]=1;
            }   
        }
        return reachable[n-1];
    }
};



