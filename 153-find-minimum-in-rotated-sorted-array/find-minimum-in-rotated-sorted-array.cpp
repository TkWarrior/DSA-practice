class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = (low+high)/2;
        int mini = nums[mid];
        //edge cases
        //for already sorted array
        if(nums[low]<nums[high]){
            return nums[low];
        }
        // for array size equal to 1
        if(nums.size()==1){
            return nums[low];
        }

        // binary search
        while(low<=high){
          mid = (low+high)/2;
           if(nums[mid]>=nums[low]){
                mini = min(mini,nums[low]);
                low = mid+1;
           }
           if(nums[mid]<=nums[high]){
                mini = min(mini,nums[mid]);
                high = mid-1;
           }
            
        }
      return mini;
    }
};