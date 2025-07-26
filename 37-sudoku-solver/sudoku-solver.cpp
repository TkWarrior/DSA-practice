class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>&board){
        for(int row = 0 ; row<board.size() ; row++){
            for(int col = 0 ; col<board[0].size() ; col++){
                // first we've to check for the empty cell then only we've to do the recursion call
                if(board[row][col] == '.'){
                    // we've to try out all possible combination from 1 to 9
                    for(char c = '1' ; c<='9' ; c++){
                        // validity check 
                        if (isValid(board , row , col , c)){
                            board[row][col] = c;
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>&board , int row , int col , char c){
            for(int i=0 ; i<9 ; i++){
                // first we will check the row to find the valid condition 
                /* Each of the digits 1-9 must occur exactly once in each row.*/
                if(board[row][i] == c){
                    return false;
                }
                /* Each of the digits 1-9 must occur exactly once in each coloumn.*/
                if(board[i][col] == c){
                    return false;
                }
                /*Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.*/
                if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c){
                    return false;
                }
            }
        return true;
    }
};