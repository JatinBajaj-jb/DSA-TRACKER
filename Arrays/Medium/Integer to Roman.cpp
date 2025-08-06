// Approach : we created two vectors of values and their corresponding symbols , we check if the number is divisble by the value of the index, if yes , we get times by num/val;
class Solution {
public:
    string intToRoman(int num) {
        string result="";
        int indx=0;
        vector<int> val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<13;i++){
            if(num==0){
                break;
            }
            int times=num/val[i];
            while(times--){
                result+=sym[i];
            }
            num=num%val[i];
        }
        return result;
    }
};
