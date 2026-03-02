class Solution {
public:
    bool bs(vector<int>&row , int target){
        int s = 0 ;
        int n = row.size();
        int e = n-1 ;
        int mid ;
        
        while(s<=e){
            mid = s + (e-s)/2;
            if(row[mid]==target){
                return true ;
            }else if(row[mid]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();

        for(int i = 0 ; i<n ; i++){
            if(bs(matrix[i],target)){
                return true;
            }
        }

        return false;
    }
};