// Approach 1 : I used slow and fast pointer method to get the solution 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};
