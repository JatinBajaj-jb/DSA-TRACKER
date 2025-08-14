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
// Approach 2 : I seperated two list then used a merger feature on them , 
class Solution {
private:
    ListNode* mergetwo(ListNode* l1,ListNode* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val>l2->val){
            l2->next=mergetwo(l1,l2->next);
            return l2;
        }
        else{
            l1->next=mergetwo(l1->next,l2);
            return l1;
        }
    }

    ListNode* merger(int st,int end,vector<ListNode*>& lists){
        if(st==end){
            return lists[st];
        }
        if(st>end){
            return NULL;
        }
        int mid=st+(end-st)/2;
        // if(mid-st+1==2){
        //     return mergetwo(lists[st],lists[st+1]);
        // }
        ListNode* l1=merger(st,mid,lists);
        ListNode* l2=merger(mid+1,end,lists);
        ListNode* ans=mergetwo(l1,l2);
        return ans;
        }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int st=0;
        int end=lists.size()-1;
        ListNode* result=merger(st,end,lists);
        return result;
    }
};
