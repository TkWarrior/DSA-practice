class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx_area = INT_MIN;
        int n = height.size();
        int i = 0 ;
        int j = n-1 ;
        int area = 0 ;

        while(i<j){
            if(height[i]>height[j]){
                area = height[j]*(j-i);
                j--;
            }else{
                area = height[i]*(j-i);
                i++ ;
            }
            mx_area = max(mx_area,area);
        }

        return mx_area;
    }
};