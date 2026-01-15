class Solution {
public:
    int trap(vector<int>& height) {
       int total = 0 ;
       int ind = 0 ;
       int n = height.size();
       int left_max = 0  ;
       int right_max = 0;
       int max_height = height[0];

       for(int i = 1 ; i<n ; i++){
            if(height[i]>max_height){
                max_height = height[i];
                ind = i ; 
            } 
       }
       cout<<ind ;
        // solving left part
       for(int i = 0 ; i<ind ; i++){
            if(left_max>height[i]){
                total += left_max-height[i];
            }else{
                left_max = height[i];
            }
       }
       // solving for the right part

       for(int i = n-1 ; i>ind ; i--){
            if(right_max>height[i]){
                total += right_max-height[i];
            }else{
                right_max = height[i];
            }
       }

    return total ;
    }
};