// Approach 1 : I just brute force to get the solution 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* curr=head;
        while(curr->next->next){
            ListNode* end1=curr;
            while(end1->next->next){
                end1=end1->next;
            }
            ListNode* temp=end1;
            end1=end1->next;
            end1->next=curr->next;
            curr->next=end1;
            temp->next=NULL;
            if(!end1->next->next) break;
            else{
                curr=end1->next;
            }
        }
    }
};
// Approach 2 : I used deque to solve this question 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* curr=head->next;
        deque<ListNode*> dq;
        while(curr){
            dq.push_back(curr);
            curr=curr->next;
        }
        ListNode* curr1=head;
        while(!dq.empty()){
            curr1->next=dq.back();
            curr1=curr1->next;
            dq.pop_back();
            if(dq.empty()) break;

            curr1->next=dq.front();
            curr1=curr1->next;      
            dq.pop_front();
        }
        curr1->next=NULL;
    }
};
