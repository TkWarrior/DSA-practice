class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       //1) 1st transporse the matrix
       //2) then reverse its rows
       int m = matrix.size();
       for(int i = 0 ; i<m-1 ; i++){
            for(int j = i+1 ; j<m ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
       }
       for(int i = 0 ; i<m ; i++){
            reverse(matrix[i].begin(),matrix[i].end());
       }
    }
};