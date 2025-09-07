class Solution {
public:
    bool isValid(vector<vector<char>>&board , int i , int j){
        int m = board.size();
        int n = board[0].size();
        if(i>=0 && i<m && j>=0 && j<n && board[i][j]=='O'){
            return true;
        }

        return false;
    }
    void dfs(vector<vector<char>>&board , int i , int j){
        
        board[i][j] = '$';
        if(isValid(board , i+1 , j)){
           
            dfs(board , i+1, j);
        }
        if(isValid(board , i-1 , j)){
           
            dfs(board , i-1, j);
        }
        if(isValid(board , i , j-1)){
           
            dfs(board , i, j-1);
        }
        if(isValid(board , i , j+1)){
           
            dfs(board , i, j+1);
        }
        
    
    }
    void solve(vector<vector<char>>& board) {
   

        int m  = board.size();
        int n  = board[0].size();
        // securing boarder region
        for(int i = 0 ; i < n ; i++){ // first row
            if(board[0][i]=='O'){
              dfs(board , 0, i);
            }
        }

        for(int i = 0 ; i < m ; i++){ // first coloumn
            if(board[i][0]=='O'){
                dfs(board , i, 0);
            }
        }

        for(int i = 0 ; i < m ; i++){ // first last coloumn
            if(board[i][n-1]=='O'){
                dfs(board , i, n-1);
            }
        }
       
        for(int i = 0 ; i < n ; i++){ // last row
            if(board[m-1][i]=='O'){
                dfs(board , m-1, i);
            }
        }

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(board[i][j]=='O'){
                  board[i][j] = 'X';    
                }
                if(board[i][j]=='$'){
                  board[i][j] = 'O';   
                }
            }
        }

      
    }

};