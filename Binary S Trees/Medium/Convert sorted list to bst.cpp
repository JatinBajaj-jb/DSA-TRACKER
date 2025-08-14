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
