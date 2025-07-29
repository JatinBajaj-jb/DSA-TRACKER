// Approach 1: I tried to do this myself , it was not that easy tho
class Solution {
private:
    void solve(vector<char>&chars){
        int j=0;
        for(int i=0;i<chars.size();){
            int count=1;
            char current=chars[j];
            while(j+1<chars.size() && chars[j+1]==current){
                count++;
                j++;
            }
            chars[i]=current;
            if(count>1){
                string temp=to_string(count);
                for(char val:temp){
                    i++;
                    chars[i]=val;
                }
            }
            i++;
            j++;
            if(j>=chars.size()){
                chars.erase(chars.begin()+i,chars.end());
                break;
            }
        }
    }
public:
    int compress(vector<char>& chars) {
        solve(chars);
        return chars.size();
    }
};
// Approach 2: I did cleaner and more sophisticated code lines , tbh i didnt find a major difference in my style of code and this approach , but i learned about all the optimization i can make and how small things really adds ups
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int indx=0;
        int i=0;
        while(i<n){
            char current=chars[i];
            int count =1;
            while(i+1<n && chars[i+1]==current){
                i++;
                count++;
            }
            chars[indx]=current;
            indx++;
            if(count>1){
                string temp=to_string(count);
                for(char val:temp){
                    chars[indx]=val;
                    indx++;
                }
            }
            i++;
        }
        return indx;
    }
};
