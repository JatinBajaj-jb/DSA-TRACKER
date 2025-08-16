// Approach 1: normal recursion 
class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode* temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;
    }
};
// Approach 2: I used the properties of bst 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root){
            return 0;
        }
        if(root->val<low){
            return rangeSumBST(root->right,low,high);
        }
        else if(root->val>high){
            return rangeSumBST(root->left,low,high);
        }
        else {
            return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
        
    }
};
