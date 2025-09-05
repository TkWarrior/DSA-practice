class Solution {
public:
    bool isValid(int row , int col , int initialColor , vector<vector<int>>&res , int m , int n ){

        if(row>= 0 && row<m && col>=0 && col<n && res[row][col] == initialColor){
            return true;
        }

        return false;
    }
    void dfs(vector<vector<int>>&res , vector<vector<int>>&image , int sr ,int sc , int colored , int initialColor){
        int m = image.size();
        int n = image[0].size();
        int row = sr ; 
        int col = sc ; 
        if(isValid(row-1 , col , initialColor , res , m , n)){
            res[row-1][col] = colored ; 
            dfs(res , image , row-1 , col , colored , initialColor);
        }
         if(isValid(row+1 , col , initialColor , res , m , n)){
            res[row+1][col] = colored ; 
            dfs(res , image , row+1 , col , colored , initialColor);
        }
        if(isValid(row , col-1 , initialColor , res , m , n)){
            res[row][col-1] = colored ; 
            dfs(res , image , row , col-1 , colored , initialColor);
        }
        if(isValid(row , col+1 , initialColor , res , m , n)){
            res[row][col+1] = colored ; 
            dfs(res , image , row , col+1 , colored , initialColor);
        }

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        
        vector<vector<int>>res = image; 
        int initialColor = image[sr][sc];
        res[sr][sc] = color;
        if(initialColor == color){
            return image;
        }
        dfs(res , image , sr , sc , color , initialColor);

    return res;   

    }
};