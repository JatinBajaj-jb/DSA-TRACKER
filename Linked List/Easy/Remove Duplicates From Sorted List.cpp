// Approach 1 : I used simple traversal to reach to the optimal solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        else if(!head->next) return head;
        ListNode* curr=head->next;
        ListNode* prev=head;
        while(curr){
            if(curr->val!=prev->val){
                prev->next=curr;
                prev=curr;
            }
            curr=curr->next;
        }
        prev->next=nullptr;
        return head;
        
    }
};
