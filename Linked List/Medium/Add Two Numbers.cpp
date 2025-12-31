// Approach 1 : I used recursion to get the two numbers 

long long solve(ListNode* l1){
    if(!l1) return 0;
    long long result=solve(l1->next);
    return result*10+l1->val;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long n1=solve(l1);
        long long n2=solve(l2);
        long long  result= n1+n2;
        ListNode dummy(0);
        if(n1==0 && n2==0) return new ListNode(0);
        ListNode* curr=&dummy;
        while(result>0){
            int currN=result%10;
            result/=10;
            curr->next=new ListNode(currN);
            curr=curr->next;
        }
        return dummy.next;     
    }
};
// Approach 2 : I used recurion to build the listnode one step at a time 
class Solution {
    ListNode* solve(ListNode* l1,ListNode* l2,int carry){
        if(!l1 && !l2) return carry==0?nullptr: new ListNode(carry);
        int sum1=l1==nullptr?0:l1->val;
        int sum2=l2==nullptr?0:l2->val;

        int sum=sum1+sum2+carry;
        if(sum==sum%10) carry=0;
        else carry=1;

        ListNode* curr=new ListNode(sum%10);
    
        if(!l1) curr->next=solve(l1,l2->next,carry);
        else if(!l2) curr->next=solve(l1->next,l2,carry);
        else curr->next=solve(l1->next,l2->next,carry);
        return curr;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result=solve(l1,l2,0);
        return result;
    }
};
