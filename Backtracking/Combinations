class Solution {
    int s;
private:
    void find(vector<vector<int>> &ans,vector<int> &l,vector<int> &temp,int indx){
        if(temp.size()==s){
            ans.push_back(temp);
            return;
        }
        for(int i=indx;i<l.size();i++){
            temp.push_back(l[i]);
            find(ans,l,temp,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        s=k;
        vector<vector<int>> ans;
        vector<int> l(n,0);
        vector<int> temp;
        for(int i=1;i<=n;i++){
            l[i-1]=i;
        }
        find(ans,l,temp,0);
        return ans;
    }
};
