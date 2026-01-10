class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
         
        int n = matrix.size() ;
        // every row and and its corresponding coloumn should not contain duplicate value
        for(int i = 0 ; i<n ; i++){
            vector<bool>rowVisited(n+1 , false);
            vector<bool>colVisited(n+1 , false);
            for(int j = 0 ; j<n ; j++){
                int rVal = matrix[i][j]; // matrix[0][1]
                int cVal = matrix[j][i]; // matrix[1][0]

                if(rowVisited[rVal]==true || colVisited[cVal]==true){
                    //invalid matrix
                    return false;
                }
                rowVisited[rVal] = true ;
                colVisited[cVal] = true ;

            }
        }

        return true ; 
    }
};