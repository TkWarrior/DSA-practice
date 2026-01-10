class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
         
        int n = matrix.size() ;
        // every row and and its corresponding coloumn should not contain duplicate value
        for(int i = 0 ; i<n ; i++){
            // vector<bool>rowVisited(n+1 , false);
            // vector<bool>colVisited(n+1 , false);
            unordered_map<int,bool>mp1 ;
            unordered_map<int,bool>mp2 ;
            for(int j = 0 ; j<n ; j++){
                int rVal = matrix[i][j]; // matrix[0][1]
                int cVal = matrix[j][i]; // matrix[1][0]

                if(mp1[rVal]==true || mp2[cVal]==true){
                    //invalid matrix
                    return false;
                }
                mp1[rVal] = true ;
                mp2[cVal] = true ;

            }
        }

        return true ; 
    }
};