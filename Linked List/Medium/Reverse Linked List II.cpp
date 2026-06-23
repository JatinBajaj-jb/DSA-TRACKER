// Attempt 1 : I increase the complexity of the program leading to memory leakage 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return nullptr;

        ListNode* temp=new ListNode();
        ListNode* curr=head;

        for(int i=1;i<=right;i++){
            if(i==left-1) temp=curr;
            curr=curr->next;
        }
        ListNode* temp2=curr->next;
        ListNode* temp3=temp->next;
        temp->next=curr;
        // temp3->next=temp2;
        curr=temp3->next;
        ListNode* prev=temp3;
        ListNode* forward=new ListNode();

        while(left<right-1){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            left++;
        }
        temp3->next=temp2;

        return head;
    }
};

// Approach 2 : I used head insertion method 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* prev=dummy;

        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        ListNode* next=nullptr;

        for(int i=left;i<right;i++){
            next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
        }
        return dummy->next;
        
    }
};
