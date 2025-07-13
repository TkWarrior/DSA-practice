class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 ;
        int max_len = 0;
         while(r<n){
            if(nums[r]==0){
                k--;
            }
            while(k<0 ){
                if(nums[l]== 0 ){
                    k++;
                }
                l++;
            }
            max_len = max(max_len , r-l+1);
            r++;
         }
        return max_len;
    }
   
};