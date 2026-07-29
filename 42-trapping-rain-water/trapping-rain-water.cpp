class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ind = 0 ;
        int max_height = height[0];
        int water = 0;

        for(int i = 1 ; i<n ; i++){
            if(height[i]>max_height){
                max_height = height[i];
                ind = i;
            }
        }

        int left_max = 0 ;

        for(int i = 0 ; i<ind ; i++){
            if(height[i]<left_max){
                water +=  left_max - height[i] ;
            }else{
                left_max = height[i];
            }
        }

        int right_max = 0;

        for(int i = n-1 ; i>ind ; i--){
            if(height[i]<right_max){
                water += right_max - height[i];
            }else{
                right_max = height[i];
            }
        }

        return water ;
    }
};