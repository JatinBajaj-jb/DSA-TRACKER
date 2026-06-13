// Approach 1 : I tried to physically rotate the list everytime 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n=0;
        ListNode* count=head;
        while(count){
            count=count->next;
            n++;
        }
        int rotations=k%n;
        while(rotations--){
            ListNode* curr=head;
            while(curr->next->next){
                curr=curr->next;
            }
            curr->next->next=head;
            head=curr->next;
            curr->next=NULL;
        }
        return head;        
    }
};
// Approach 2 : I used it by making a circular linked list and finding out the new tail and disconnecting it 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head ||!head->next) return head;
        int n=1;
        ListNode* curr=head;
        while(curr->next){
            n++;
            curr=curr->next;
        }
        curr->next=head;
        ListNode* tail=head;
        k%=n;
        for(int i=0;i<n-k-1;i++){
            tail=tail->next;
        }
        head=tail->next;
        tail->next=NULL;
        return head;
    }
};
