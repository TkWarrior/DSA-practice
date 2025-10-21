class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0 ; 
        int n = nums.size();
        int j  = n-1 ; 

        while(i<j){
            if(nums[i]%2==1 && nums[j]%2 == 0){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }else if (nums[i]%2==1 && nums[j]%2==1){
                j--;
            }else{
                i++;
            }
           
        }

        return nums;
    }
};