// Approach 1: I just merged all the lists together and applied bubble sort to them 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        ListNode* start=lists[0];
        ListNode* prevhead=NULL;
        for(ListNode* val:lists){
            if(val==NULL){
                continue;
            }
            if(prevhead){
                prevhead->next=val;
            }
            while(val->next){
                val=val->next; 
            }
            prevhead=val;
        }
        if(!start){
            return NULL;
        }
        if(start->next==NULL)return start;
        
        for(ListNode* s1=start;s1;s1=s1->next){
            for(ListNode* s2=start;s2;s2=s2->next){
                if(s2->val>s1->val){
                    swap(s2->val,s1->val);
                }
            }
        }
        return start;
        
    }
};
