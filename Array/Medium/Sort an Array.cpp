// Approach 1 : Selection Sort(TLE)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        for(int i=0;i<n;i++){
            curr=i;
            for(int j=i+1;j<n;j++){
                if(nums[curr]>nums[j]){
                    curr=j;
                }
            }
            swap(nums[i],nums[curr]);
        }
        return nums;
    }
};

// Approach 2: Merge Sort 
class Solution {
private:
    void merge(vector<int>& nums,int low,int high,int mid){
        vector<int> temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return;
    }
    void mergeSort(vector<int>& nums,int left ,int right){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);

        merge(nums,left,right,mid);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

// Approach 3: I used counting sort 
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int minE=*min_element(nums.begin(),nums.end());
        int maxE=*max_element(nums.begin(),nums.end());
        int i=0;
        for(int num=minE;num<=maxE;num++){
            while(mp[num]>0){
                nums[i++]=num;
                mp[num]--;
            }
        }
        return nums;
    }
};

mmmmmMmmMmmm
