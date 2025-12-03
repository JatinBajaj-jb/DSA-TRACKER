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
// Approach 2 : I used two pointer approach 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        int currindx=1;
        int size=1;
        if(!fast->next && n==1) return nullptr;
        while(fast && fast->next){
            size++;
            fast=fast->next;
            if(currindx>n){
                slow=slow->next;
            }
            currindx++;
        }
        if(size-n-1==-1) return head->next;
        slow->next=slow->next->next;
        return head;
    }
};
