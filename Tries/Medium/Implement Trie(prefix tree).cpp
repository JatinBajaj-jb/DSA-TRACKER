class Trie {
public:
    struct TrieNode{
        bool IsEnd;
        TrieNode* arr[26];
    };
    TrieNode* getNode(){
        TrieNode* newnode=new TrieNode;
        newnode->IsEnd=false;
        for(int i=0;i<26;i++){
            newnode->arr[i]=NULL;
        }
        return newnode;
    }
    TrieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        TrieNode* crawer=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int indx=ch-'a';
            if(crawer->arr[indx]==NULL){
                crawer->arr[indx]=getNode();
            }
            crawer=crawer->arr[indx];
        }
        crawer->IsEnd=true;
    }
    bool search(string word) {
        TrieNode* crawer=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int indx=ch-'a';
            if(crawer->arr[indx]==NULL){
                return false;
            }
            crawer=crawer->arr[indx];
        }   
        if(crawer && crawer->IsEnd){
            return true;
        }
        return false;
    }
    bool startsWith(string prefix) {
        TrieNode* crawer=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            int indx=ch-'a';
            if(crawer->arr[indx]==NULL){
                return false;
            }
            crawer=crawer->arr[indx];
        }
        return true;
    }
};
