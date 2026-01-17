class Solution {
public:
    int trap(vector<int>& height) {
        int total_water = 0 ;
        int left_max = 0 ;
        int right_max = 0 ;
        int max_height = height[0] ; // this we will calculate one time ; 
        int n = height.size();
        int ind = 0 ;

        for(int i = 1 ; i<n ; i++){
            if(height[i]>max_height){
                max_height = height[i];
                ind = i ;
            }
        }

        for(int i = 0 ; i<ind ; i++){
            if(left_max > height[i]){
                total_water += left_max - height[i];
            }else{
                left_max = height[i];
            }
        }

        for(int i = n-1 ; i>ind ; i--){
            if(right_max > height[i]){
                total_water += right_max - height[i];
            }else{
                right_max = height[i];
            }
        }

        return total_water;
    }
};