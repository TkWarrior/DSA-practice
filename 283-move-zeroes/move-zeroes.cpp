class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int j = 0;
       int i = 0;
       int n  = nums.size();
       while(i < n){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
       }
    }
};