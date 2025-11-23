// Approach 1: I tried to use bfs along with another queue , it got stuck at the test cases
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        stack<int> st;
        queue<int> valq;
        st.push(root->val);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                curr->val=st.top();
                st.pop();
                if(curr->left){
                    q.push(curr->left);
                    valq.push(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    valq.push(curr->right->val);
                }
            }
            while(!valq.empty()){
                st.push(valq.front());
                valq.pop();
            }
        }
        return root;
        
    }
};
// Approach 2 : I used simple recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root->right,root->left);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
