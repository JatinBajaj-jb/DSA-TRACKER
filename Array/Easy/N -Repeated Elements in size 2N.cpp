// Approach 1 : I used the brute force approach 
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp1;
        unordered_map<char,string> mp2;
        int indx=0;
        int count=0;
        string temp="";
        stringstream ss(s); 
        while(getline(ss,temp,' ')){
            count++;
            if(count>pattern.size()) return false;
            if(mp1.find(temp)==mp1.end()){
                if(mp2.find(pattern[indx])==mp2.end()){
                    mp1[temp]=pattern[indx];
                    mp2[pattern[indx]]=temp;
                }
                else return false;
            }
            else{
                if(mp1[temp]!=pattern[indx] || mp2[pattern[indx]]!=temp)return false;
            }
            indx++;
        }
        return indx==pattern.length();
    }
};
// Approach 2 : I used set to find the repeated element 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> st;
        for(int& val:nums){
            if(st.find(val)!=st.end()) return val;
            else st.insert(val);
        }
        return -1;
    }
};
// Approach 3 : the repeated element that has freq n cant be seperated for more than 2 element
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]) return nums[i];
        }
        return nums.back();
    }
};
