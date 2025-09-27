class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int l = 0 ; 
         int r = 0 ; 
         int n = nums.size();

         while(r<n){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
            r++;
         }

    }
};