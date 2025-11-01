// Approach 1: I used a recursion based strategy to remove the elements with the help of a hash map;
class Solution {
private:
    ListNode* remove(int target,ListNode* head){
        if(head->val==target){
            return head->next;
        }
        else{
            ListNode* temp=head;
            while(temp->next && temp->next->val!=target){
                temp=temp->next;
            }
            if(temp->next && temp->next->val==target){
                temp->next=temp->next->next;
            }
            return head;
        }
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp=head;
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }
        for(int& val:nums){
            int i=mp[val];
            while(i>0){
                head=remove(val,head);
                i--;
            }
        }
        return head;
    }
};
// Approach 2 : I used set with traversal of linked list:
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int& val:nums){
            st.insert(val);
        }
        ListNode* temp2=head;
        while(temp2->next){
            if(st.find(temp2->next->val)!=st.end()){
                temp2->next=temp2->next->next;
            }
            else{
                temp2=temp2->next;
            }
        }
        if(st.find(head->val)==st.end()){
            return head;
        }
        else{
            return head->next;
        }
    }

