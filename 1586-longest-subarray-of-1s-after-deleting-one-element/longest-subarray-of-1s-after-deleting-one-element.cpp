class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // nums[r] == 0 r++ , len = r-l+1 
        // intuition we will return the maximum window size where zero count is 1
        int l = 0 ; 
        int r = 0 ; 
        int count_zero = 0 ; 
        int n = nums.size();
        int max_len = 0 ;
       
        while(r<n){

            if(nums[r]==0){
                count_zero++;
            }

            while(count_zero>1){
                if(nums[l]==0){
                      count_zero--;
                }
               
                l++;    
            }
   
            max_len = max(max_len , r-l+1);
           
            r++;
        }

        return max_len-1;
    }
};