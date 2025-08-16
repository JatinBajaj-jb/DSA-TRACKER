// Approach 1 : I just used basic checks to solve the question 
class Solution{
private:
    bool check(vector<vector<char>>& board,int rows,int cols,int rowe,int cole){
        set<char> st;
        for(int i=rows;i<=rowe;i++){
            for(int j=cols;j<=cole;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<char> st;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            set<char> st;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.'){
                    continue;
                }
                if(st.find(board[j][i])!=st.end()){
                    return false;
                }
                st.insert(board[j][i]);
            }
        }
        for(int rows=0;rows<9;rows+=3){
            int rowe=rows+2;
            for(int cols=0;cols<9;cols+=3){
                int cole=cols+2;
                if(!check(board,rows,cols,rowe,cole)){
                    return false;
                }
            }
        }
        return true;
    }
};
// Approach 2 : I used a string set to store the info about rows ,cols,and box:
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                string row=string(1,board[i][j])+"r"+to_string(i);
                string col=string(1,board[i][j])+"c"+to_string(j);
                string box=string(1,board[i][j])+"b"+to_string(i/3)+"-"+to_string(j/3);
                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;  
    }
};
