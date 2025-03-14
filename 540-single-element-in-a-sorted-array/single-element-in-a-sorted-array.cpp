class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        int mid;
       
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-2]!=nums[n-1]){
            return nums[n-1];
        }
        
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid-1]!=nums[mid]){
                break;
            }
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid-1]==nums[mid])){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return nums[mid];
    }
};