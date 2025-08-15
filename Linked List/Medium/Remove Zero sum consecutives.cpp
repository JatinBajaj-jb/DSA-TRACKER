class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        int netsum=0;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        mp[0]=dummy;
        ListNode* left=head;
        ListNode* curr=head;
        
        while(curr){
            netsum+=curr->val;
            if(mp.find(netsum)!=mp.end()){
                ListNode* temp=mp[netsum];
                ListNode* start=temp->next;
                int nsum=netsum;
                while(start!=curr){
                    nsum+=start->val;
                    mp.erase(nsum);
                }
                temp->next=curr->next;
            }
            else{
                mp[netsum]=curr;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};
