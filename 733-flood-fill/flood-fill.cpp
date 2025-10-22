class Solution {
public:
    bool isValid(vector<vector<int>>&image , int m , int n , int new_i , int new_j ,int old_col ){
        if(new_i >= 0 && new_i<m && new_j>=0 && new_j<n && image[new_i][new_j]==old_col ){
            return true;
        }

        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size() ; 
        int n = image[0].size() ; 

        vector<vector<int>>dir = {{1,0} , {0,1} ,{-1,0} ,{0,-1}};

        queue<pair<int ,int>>q;

        int old_col = image[sr][sc];// save the copy of old color
        image[sr][sc] = color ;
        q.push({sr,sc});
        if(old_col == color){
            return image;
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int , int>curr = q.front() ; 
                q.pop() ; 
                
                int old_i = curr.first ;
                int old_j = curr.second ; 

                for(vector<int>&arr : dir){
                    int new_i = old_i + arr[0] ; 
                    int new_j = old_j + arr[1] ; 
                    if(isValid(image , m , n , new_i , new_j, old_col)){
                        image[new_i][new_j] = color ; 
                        q.push({new_i , new_j});
                    }
                }
            }
        }

        return image ; 
    }
};