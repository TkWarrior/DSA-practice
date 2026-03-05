class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0 ;
        int j = 0 ;

        while(j<n){
            if(nums[j]!=0){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp ;
                i++;
            }
            j++; 
        }

    }
};