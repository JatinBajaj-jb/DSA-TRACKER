// Approach 1 : iterative approach :
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* f1=head;
        ListNode* f2=head->next;
        ListNode* heads=f2;
        ListNode* prev=NULL;
        while(f2){
            if(prev){
                prev->next=f2;
            }
            f1->next=f2->next;
            f2->next=f1;
            prev=f1;
            f1=f1->next;
            if(!f1){
                break;
            }
            f2=f1->next;
        }
        return heads;
        
    }
};
// Approach 2: Recursive approach : 
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
