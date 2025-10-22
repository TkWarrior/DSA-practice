class Solution {
public:
    bool isValid(int new_i , int new_j , vector<vector<int>>& grid ,int m , int n ){
        // orange fresh hona chahiye aur within the boundary hona chahiye means matrix ke andar
        if(new_i >=0 && new_i < n && new_j>=0 && new_j<m && grid[new_i][new_j]==1){
            return true ;
        }

        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // create adjacency list ;
        
        int n = grid.size();
        int m = grid[0].size() ; 
        queue<pair<int ,int>>q ; 
        vector<vector<int>>dir = {{1,0} , {0,1} , {-1 , 0} , {0 , -1}};
        int fresh_cnt = 0 ;
        int minute = 0 ;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({i , j });

                }else if(grid[i][j]==1){
                    fresh_cnt++;
                }
            }
        }

        if(fresh_cnt == 0 ){
            return 0; 
        }

        while(!q.empty()){      
            int size = q.size();
            while(size--){
                pair<int , int> curr = q.front();
                q.pop();
                int old_i = curr.first ; 
                int old_j = curr.second ; 

                for(vector<int>&arr:dir){
                    int new_i = old_i + arr[0];
                    int new_j = old_j + arr[1];

                    if(isValid(new_i , new_j , grid , m , n)){
                        grid[new_i][new_j] = 2 ; 
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