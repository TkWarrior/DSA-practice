class Solution {
public:
    // same count the no of dfs call when ever X appear
    void dfs(vector<vector<char>>&res ,int i , int j , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n || res[i][j]!='X'){
            return ;
        }
        res[i][j] = '#';
        dfs(res , i-1 , j , m , n);
        dfs(res , i+1 , j , m , n );
        dfs(res , i , j-1 , m , n);
        dfs(res , i , j+1 , m , n);
    }
    int countBattleships(vector<vector<char>>& board) { 
        int m  = board.size();
        int n = board[0].size();
        int cnt = 0 ;

        vector<vector<char>>res = board;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(res[i][j]=='X'){
                    dfs(res , i , j , m , n );
                    cnt++;
                }
            }
        }

        return cnt;

    }
};