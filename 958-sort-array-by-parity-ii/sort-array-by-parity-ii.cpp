class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // matlab ki odd index pe odd value and even index pe even value

       int i = 0 ; 
       int j = 1 ;
        int n = nums.size();

       while(i<n && j<n){
            if(nums[i]%2==0){
                i+=2;
            }
            else if(nums[j]%2 == 1){
                j+=2 ; 
            }else{
                swap(nums[i] , nums[j]);
            }
       }

       return nums;
    }
};