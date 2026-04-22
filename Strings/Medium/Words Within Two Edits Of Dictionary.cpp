// Approach 1 : I did the brute force solution 
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(auto word1: queries){
            for(auto word2:dictionary){
                int maxCount=0;
                for(int i=0;i<word1.size();i++){
                    if(word1[i]!=word2[i]) maxCount++;
                }
                if(maxCount<=2){
                    result.push_back(word1);
                    break;
                }
            }
        }
        return result;
    }
};
