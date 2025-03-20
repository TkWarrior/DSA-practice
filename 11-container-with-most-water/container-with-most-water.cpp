class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int maxi = INT_MIN;
        while(i<j){
            if(height[i]>height[j]){
                maxi = max(maxi,height[j]*(j-i));
                j--;
            }
            else{
                maxi = max(maxi,height[i]*(j-i));
                i++;
            }
            // i++;
        }
        // i=0;
        // while(i<j){
        //     if(height[i]>height[j]){
        //         maxi = max(maxi,height[j]*(j-i));
        //     }
        //     else{
        //         maxi = max(maxi,height[i]*(j-i));
        //     }
        //     j--;
        // }
        return maxi;
    }
};