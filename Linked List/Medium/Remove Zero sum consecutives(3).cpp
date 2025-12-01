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

// solve 2 : I had problem with the question as it involved an unique solution to solve , we used a hashmap to store the sum->ListNode , when the sum repeat its value 
// thus we get a [...] 
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        dummy->next =head;
        ListNode* curr=dummy;

        int sum=0;
        while(curr){
            sum+=curr->val;
            mp[sum]=curr;
            curr=curr->next;
        }
        ListNode* result=new ListNode(0);
        ListNode* curr1=result;
        sum=0;
        while(curr1){
            sum+=curr1->val;
            curr1->next=mp[sum]->next;
            curr1=curr1->next;
        }
        return result->next;
    }
};
