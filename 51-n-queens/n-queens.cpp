class Solution {
public:
    bool isSafe(vector<string>&board , int row , int col ,int n ){
        int saveRow = row;
        int saveCol = col ;
        // checking lower diagonal if there is any queen present or not
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        // checking upper diagonal for queen 
        row = saveRow;
        col = saveCol;
         while(row>=0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        //checking the left side for queen
        row = saveRow;
        col = saveCol;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        return true;

    }
    void solve(int col , vector<string>&board ,vector<vector<string>>&ans , int n  ){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0 ; row<n ; row++){
            if (isSafe(board , row , col , n)){
                board[row][col] = 'Q';
                solve(col+1 , board , ans , n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string path(n ,'.');
        for(int i = 0 ; i < n ; i++){
            board[i] = path;
        }
        solve(0 , board  , ans , n);
        return ans;
    }
};