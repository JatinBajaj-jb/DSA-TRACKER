// Approach 1 : I used O(N) time complexity for the brute force solution 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* curr=head;
        unordered_map<Node*,Node*> mp;
        while(curr){
           mp[curr]=new Node(curr->val);
           curr=curr->next;
        }
        curr=head;
        while(curr){
            mp[curr]->next=mp[curr->next];
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
    }
};
// Approach 2 : I used Binary Search 

C++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return n-1;
        if(nums[0]>nums[1]) return 0;
        else if(nums[n-1]>nums[n-2]) return n-1;

        int low=1;
        int high=n-2;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

            else if(nums[mid]<nums[mid+1]) low=mid+1;
            else high=mid-1;    
        }
        return -1;
    }
};
