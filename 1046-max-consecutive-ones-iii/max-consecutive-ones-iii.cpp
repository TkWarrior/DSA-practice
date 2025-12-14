class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int maxi = 0 ;
        int l = 0 ; 
        int r = 0 ; 
        int no_of_zero = 0 ;
       
        while(r<n){
            if(nums[r]==0){
                k--;
            }
            while(k<0){
                if(nums[l]==0){
                    k++;
                }
                l++;
            }
            maxi = max(maxi , r-l+1);
            r++;
        }

        return maxi ;
    }
};