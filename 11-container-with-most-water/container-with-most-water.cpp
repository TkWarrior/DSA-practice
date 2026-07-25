class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0 ;
        int max_area = INT_MIN ;
        int i = 0 ;
        int j = height.size()-1 ;

        while(i<j){
            if(height[i]<height[j]){
                area = (j-i)*height[i];
                i++;
            }else{
                area = (j-i)*height[j];
                j--;
            }
            max_area = max(area , max_area);
        }

        return max_area;
    }
};