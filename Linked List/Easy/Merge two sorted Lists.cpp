// I used a recursive approach to the question
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<list2->val){
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};
// Approach 2 : I used iterative approach to solve the question
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* result=&dummy;
        if(!list1 && !list2) return nullptr;
        while(list1 && list2){
            if(list1->val <=list2->val){
                result->next=list1;
                list1=list1->next;
            }
            else{
                result->next=list2;
                list2=list2->next;
            }
            result=result->next;
        }
        result->next=list1?list1:list2;
        return dummy.next; 
    }
};
