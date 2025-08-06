// Approach 1: I used the queue to get the inorder traversal and used a marker to get the right most value of each segment of the tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*> q;
        TreeNode* prev=NULL;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                result.push_back(prev->val);
                if(q.empty()){
                    break;
                }
                q.push(NULL);
                continue;
            }
            prev=curr;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        return result;
    }
// Approach 2: I used recursion to check the dfs , it was quite simple and intersting ;
class Solution {
private:
    void preorder(vector<int>& result,int level,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(result.size()<level){
            result.push_back(root->val);
        }
        preorder(result,level+1,root->right);
        preorder(result,level+1,root->left);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        preorder(result,1,root);
        return result;
    }
};
};
