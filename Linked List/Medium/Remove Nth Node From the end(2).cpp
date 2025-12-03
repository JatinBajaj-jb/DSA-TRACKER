// Approach : I used basic traversal
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            size++;
        }
        if(size==1){
            return NULL;
        }
        ListNode* curr2=head;
        size=size-n-1;
        if(size==-1){
            return head->next;
        }
        while(size--){
            curr2=curr2->next;
        }
        curr2->next=curr2->next->next;
        return head;
    }
};
