// Approach : It took me alot of headaches to solve but i got it , the basic backtracking along with valid sudoku check, the only part which is tricky is the bool solved portion ,
class Solution {
bool solved=false;

private:
    void solve(vector<vector<char>>& board,int i,int j){
        if(solved){
            return ;
        }
        if(i==9){
            solved=true;
            return;
        }

        int i1=(j==8?i+1:i);
        int j1=(j==8?0:j+1);

        if(board[i][j]!='.'){   
            solve(board,i1,j1);
        }
        else{
            for(int currval=0;currval<9;currval++){
                if(checker(board,i,j,currval+49)){
                    continue;
                }
                board[i][j]=currval+49;
                solve(board,i1,j1);
                if(solved){
                    return;
                }
                board[i][j]='.';
            }
       }
    }
    bool checker(vector<vector<char>>& board,int row,int col,char d){
        for(int i=0;i<9;i++){
            if(board[row][i]==d){
                return false;
            }
            if(board[i][col]==d){
                return false;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+(row/3)*3][j+(col/3)*3]==d){
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};
