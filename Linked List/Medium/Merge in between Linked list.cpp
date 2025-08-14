class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(!list1){
            return list2;
        }else if(!list2){
            return list1;
        }
        if(!list1 && !list2){
            return NULL;
        }
        ListNode* curr=list1;
        int a1=a;
        while(a1-1>0){
            curr=curr->next;
            a1--;
        }
        ListNode* temp=curr;
        int b1=b;
        while(b1-a+1>0){
            temp=temp->next;
            b1--;
        }
        curr->next=list2;
        while(curr->next){
            curr=curr->next;
        }
        ListNode* remove=temp;
        if(temp->next){
            temp=temp->next;
        }
        remove->next=NULL;
        curr->next=temp;
        return list1; 
    }
};
