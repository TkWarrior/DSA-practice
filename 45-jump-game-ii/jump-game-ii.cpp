class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count_jump = 0 ;
        int farthest , end = 0 ;
        int far = 0 ; 
        for(int i = 0 ; i<n-1 ; i++){
            far = i+nums[i];
            farthest = max(farthest , far);

            if(i==end){
                count_jump++;
                end = farthest;
            }
        }

        return count_jump;
    }
};