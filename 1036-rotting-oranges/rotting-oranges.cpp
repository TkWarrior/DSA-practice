class Solution {
public:

    bool isValid(int new_i , int new_j , vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(new_i>=0 && new_i<m  && new_j>=0 && new_j<n && grid[new_i][new_j]==1){
            return true;
        }

        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q ;
        vector<vector<int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};   
        int m = grid.size();
        int n = grid[0].size();
        int fresh_cnt = 0 ;
        int minute = 0 ;

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
               
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh_cnt++;
                }
            }
        }

        if(fresh_cnt == 0){
            return 0;
        }

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int , int>curr = q.front();
                q.pop();

                int old_i = curr.first;
                int old_j = curr.second;

                for(vector<int>&arr : directions){
                    int new_i = old_i + arr[0];
                    int new_j = old_j + arr[1];
                    if(isValid(new_i , new_j , grid)){
                        grid[new_i][new_j] = 2;
                        q.push({new_i , new_j});
                        fresh_cnt--;
                    }
                }     
            }
             minute++;
        }

        if(fresh_cnt == 0){
            return minute-1;
        }

        return -1;
    }
};