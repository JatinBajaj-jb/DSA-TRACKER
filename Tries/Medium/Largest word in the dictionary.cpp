// Approach 1: I just made the trie and then run a dfs search on the trie:
class TrieNode{
    public:
    bool Isend;
    TrieNode* arr[26];
    string name;
    TrieNode(){
        Isend=false;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
        name="";
    }
};
class trie{
    public:
    TrieNode* root=new TrieNode;
    void Insert(string& word){
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++){
            int indx=word[i]-'a';
            if(!curr->arr[indx]){
                curr->arr[indx]=new TrieNode;
            }
            curr=curr->arr[indx];
        }
        curr->Isend=true;
        curr->name=word;
    }
};
class Solution {
private:
    void solve(TrieNode* curr,string& result,TrieNode* root){
        if(!curr){
            return;
        }
        if(curr!=root && !curr->Isend){
            return;
        }
        if(curr->name.length()>result.length() || (curr->name.length()==result.length() && curr->name<result)){
            result=curr->name;
        }
        for(int i=0;i<26;i++){
            solve(curr->arr[i],result,root);
        }
    }   
public:
    string longestWord(vector<string>& words) {
        trie t;
        for(string w:words){
            t.Insert(w);
        }
        string result="";
        solve(t.root,result,t.root);
        return result;
    }
};
