// Approach 1:I used a trie to store the words and did a simple backtracking solution:
class Solution {
private:
    vector<pair<int,int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
    class TrieNode{
    public:
        bool IsEnd;
        TrieNode* arr[26];
        TrieNode(){
            IsEnd=false;
            for(int i=0;i<26;i++){
                arr[i]=NULL;
            }
        }
    };
    class trie{
        public:
        TrieNode* root;
        trie(){
            root=new TrieNode();
        }
        void Insert(string word){
            TrieNode* curr=root;
            for(int i=0;i<word.length();i++){
                if(curr->arr[word[i]-'a']==NULL){
                    curr->arr[word[i]-'a']=new TrieNode();
                }
                curr=curr->arr[word[i]-'a'];
            }
            curr->IsEnd=true;
        }
    };
    void solve(vector<vector<char>>& board,TrieNode* root,vector<string>& result,int i,int j,int m,int n,string& holder){
        if(i>=m || j>=n || i<0 || j<0 || board[i][j]=='.'){
            return;
        }
        char curr=board[i][j];
        if(!root->arr[curr-'a']){
            return;
        }
        root=root->arr[curr-'a'];
        holder+=curr;
        if(root->IsEnd){
            result.push_back(holder);
            root->IsEnd=false;
        }
        board[i][j]='.';
        for(auto val:dir){
            int ni=i+val.first;
            int nj=j+val.second;
            solve(board,root->arr[curr-'a'],result,ni,nj,m,n,holder);
        }
        holder.pop_back();
        board[i][j]=curr;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        string holder="";
        trie t;
        for(string val:words){
            t.Insert(val);
        }
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int indx=board[i][j]-'a';
                solve(board,t.root,result,i,j,m,n,holder);
            }
        }
        return result;
    }
};
