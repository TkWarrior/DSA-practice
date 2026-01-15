class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0 ; 
        int r = n-1;
        int max_vol = INT_MIN ;
       
        while(l<r){
            max_vol = max(max_vol , min(height[l],height[r])*abs(r-l));
            if(height[l]<height[r]){
                l++;
            }else{
                 r--;
            }
        }

        return max_vol ;
    }
};