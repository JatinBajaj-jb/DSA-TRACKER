// Approach 1 : I tried to come up with the solution myself , with some changes to the code i was able to solve the solution in 0(n) time complexity 
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        unordered_map<char,int> convert={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{
            'D',500},{'M',1000}};


        for(int left=0;left<s.length();left++){
            
            if(s[left]=='I' &&(s[left+1]=='V' || s[left+1]=='X')){
                result+=(convert[s[left+1]]-1);
                left++;
            }
            else if(s[left]=='X' &&(s[left+1]=='L' || s[left+1]=='C')){
                result+=(convert[s[left+1]]-10);
                left++;
            }
            else if(s[left]=='C' &&(s[left+1]=='D' || s[left+1]=='M')){
                result+=(convert[s[left+1]]-100);
                left++;
            }
            else{
                result+=convert[s[left]];
            }
        }


        return result;
        
    }
};

// Approach 2 : I solved the question using slightly optimal solution , erasing and learning all the edge case handling 
class Solution {
public:
    int romanToInt(string s) {
        int result=0;

        unordered_map<char,int> convert={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500}
        ,{'M',1000}};

        for(int i=0;i<s.length();i++){
            if(i!=s.length()-1 && convert[s[i]]<convert[s[i+1]]){
                result-=convert[s[i]];
            }
            else{
                result+=convert[s[i]];
            }
        } 
        return result;
    }
};


