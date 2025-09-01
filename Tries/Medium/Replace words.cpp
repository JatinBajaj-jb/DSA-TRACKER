// Approach : I got to understand the stringstream approach and how to use getline in this , the main body was somewhat sudo and fixed 
class Solution {
private:
    class TrieNode{
        public:
        bool Isend;
        TrieNode* arr[26];
        string word;
        TrieNode(){
            Isend=false;
            for(int i=0;i<26;i++){
                arr[i]=NULL;
            }
            word="";
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root=new TrieNode;
        }
        void insert(string value){
            TrieNode* curr=root;
            for(int i=0;i<value.length();i++){
                int indx=value[i]-'a';
                if(!curr->arr[indx]){
                    curr->arr[indx]=new TrieNode;
                }
                curr=curr->arr[indx];
            }
            curr->Isend=true;
            curr->word=value;
        }
        string search(string value){
            TrieNode* curr=root;
            for(int i=0;i<value.length();i++){
                int indx=value[i]-'a';
                if(!curr->arr[indx]){
                    return value;
                }
                curr=curr->arr[indx];
                if(curr->Isend){
                    string temp=value.substr(0,i+1);
                    return temp;
                }
            }
            return value;
        }
    };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(string val:dictionary){
            t.insert(val);
        }
        stringstream ss(sentence);
        string word="";
        string result="";
        while(getline(ss,word,' ')){
            result+=t.search(word)+" ";
        }
        if(!result.empty()){
            result.pop_back();
        }
        return result;
    }
};
