class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0 ;
        int r = 0 ; 
        int n = nums.size() ;
        int max_len = 0 ; 

        while(r<n){
            if(nums[r]==0){
                l = r+1;
            }
            max_len = max(max_len , r-l+1);
            r++;
        }

        return max_len ; 
    }
};