// Approach 1 : I used a buffer array 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        vector<int> nums;
        int size=0;
        while(curr){
            nums.push_back(curr->val);
            curr=curr->next;
            size++;
        }
        curr=head;
        for(int i=size-1;i>=0;i--){
            curr->val=nums[i];
            curr=curr->next;
        }
        return head;
    }
};
// Approach 2 : I used recursion to get the solution 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* temp=head;

        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};


// Approach 3 : I used recursive method without using 2-3 pointers 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* newHead=reverseList(head->next);

        head->next->next=head;
        head->next=nullptr;

        return newHead;
    }
};

