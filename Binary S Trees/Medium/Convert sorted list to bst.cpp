class Solution {
private:
    TreeNode* solve(ListNode* head){
        if(!head){
            return NULL;
        }
        if(!head->next){
            return new TreeNode(head->val);
        }
        ListNode* slowprev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slowprev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* temp=new TreeNode(slow->val);
        if(slowprev){
            slowprev->next=NULL;
        }
        temp->left=solve(head);
        temp->right=solve(slow->next);
        return temp;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* base=solve(head);
        return base;
    }
};
// Approach 2 : I used vector initially and did normal divide and conquer

class Solution {
private:
    TreeNode* solve(vector<int>& list,int left,int right){
        if(left>right) return NULL;
        TreeNode* curr= new TreeNode();

        int mid=left+(right-left)/2;

        curr->val=list[mid];

        curr->right=solve(list,mid+1,right);
        curr->left=solve(list,left,mid-1);
        return curr;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> list;
        while(head){
            list.push_back(head->val);
            head=head->next;
        }
        TreeNode* root=solve(list,0,list.size()-1);
        return root;
    }
};
