// Approach 1 : just used a set to identify the repeating node and returned it 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* curr=head;
        set<ListNode*> st;
        while(curr!=NULL){
            if(st.find(curr)==st.end()){
                st.insert(curr);
                curr=curr->next;
            }
            else{
                return curr;
            }
        }
        return NULL;
    }
};
// Approach 2: we used fast and slow pointer , the point where they meet is the point of the cycle root, 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* pos=head;
                while(pos!=slow){
                    pos=pos->next;
                    slow=slow->next;
                }
                return pos;
            }
        }
        return NULL;
    }
};
