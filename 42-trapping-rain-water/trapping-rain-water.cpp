class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0 ;
        int right_max = 0 ;
        int max_height = height[0];
        int n = height.size();
        int ind =0;
        int water = 0 ;

        for(int i = 1 ; i<n ;i++){
            if(height[i]>max_height){
                max_height = height[i];
                ind = i;
            }
        }

        for(int i =0 ; i<ind ; i++){
            if(left_max>height[i]){
                water += left_max-height[i];
            }else{
                left_max = height[i];
            }
        }
        
        for(int i = n-1 ; i>ind ; i--){
            if(right_max>height[i]){
                water += right_max-height[i];
            }else{
                right_max = height[i];
            }
        }

        return water ;
    }
};