// Approach : we used a bit trie ,where we store the numbers in the trie , if the bit of the number is 1 , we search if the trie has right pointer (1) , if it does 
//   then we set the i th bit of the ans as 1 and move forward , if no , we set the i th bit of the ans as 0(already set) , and same with if the bit is 0;

class Solution {
private:
    class TrieNode{
        public:
        TrieNode* right;
        TrieNode* left;
        TrieNode(){
            right=NULL;
            left=NULL;
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root=new TrieNode;
        }
        void insert(int nums){
            TrieNode* curr=root;
            for(int i=31;i>=0;i--){
                int ibit=(nums>>i)&1;
                if(ibit==0){
                    if(!curr->left){
                        curr->left=new TrieNode;
                    }
                    curr=curr->left;
                }
                else{
                    if(!curr->right){
                        curr->right=new TrieNode;
                    }
                    curr=curr->right;
                }
            }
        }
        
    };
    void get(TrieNode* curr,int target,int i,int& ans){
            if(!curr || i<0){
                return;
            }
            int out=0;
            int n=(target>>i)&1;
            if(n==0){
                if(curr->right){
                    ans|=(1<<i);
                    get(curr->right,target,i-1,ans);
                }
                else if(curr->left){
                    get(curr->left,target,i-1,ans);
                }
            }
            else{
                if(curr->left){
                    ans|=(1<<i);
                    get(curr->left,target,i-1,ans);
                }
                else if(curr->right){
                    get(curr->right,target,i-1,ans);
                }
            }
        }
public:

    int findMaximumXOR(vector<int>& nums) {

        int result=INT_MIN;
        Trie t;
        for(int val:nums){
            t.insert(val);
        }
        for(int i=0;i<nums.size();i++){
            int ans=0;
            get(t.root,nums[i],31,ans);
            result=max(result,ans);
        }
        return result;
    }
};
