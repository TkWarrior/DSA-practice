class Solution {
public:
    // intution -  return the count of no of dfs calls
    bool isValid(vector<vector<char>>&res , int i , int j ){
        int m = res.size();
        int n = res[0].size();

        if(i>=0 && i<m && j>=0 && j<n && res[i][j]=='1'){
            return true;
        }
        return false;
    }
 
    void dfs(vector<vector<char>>& res  , int i , int j ){
        if(isValid(res , i-1 , j) ){
            res[i-1][j] = '#';
            dfs(res , i-1 , j); // checking up
        }
        if(isValid(res , i+1 , j) ){
            res[i+1][j] = '#';
            dfs(res , i+1 , j); // checking down
        }
        if(isValid(res , i , j+1) ){
            res[i][j+1] = '#';
            dfs(res , i , j+1); // checking right
        }
         if(isValid(res , i , j-1) ){
            res[i][j-1] = '#';
            dfs(res , i , j-1); // checking left
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0 ;
        vector<vector<char>>res = grid;
        
        for(int i = 0 ; i<m ; i++){
            for(int j  = 0 ; j<n ; j++){
                if(res[i][j]=='1'){
                     dfs(res , i , j );
                     cnt++;
                } 
            }
        }

        return cnt;

    }
};