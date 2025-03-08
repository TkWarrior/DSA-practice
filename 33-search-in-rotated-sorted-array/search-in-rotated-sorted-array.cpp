class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0 ;
        int e = nums.size()-1;
        while(s<=e){
            int mid =(s+e)/2;
            if(nums[mid]==target){
                return mid;
            }
            //to check if left part is sorted
            if(nums[mid]>=nums[s]){
                // if the target value is present in the left part
                if(nums[s]<=target && nums[mid]>=target){
                    e = mid-1;
                } 
                // if the target value is present in the right part
                else{
                    s= mid+1;
                }
            }
            // to check if right part is sorted
            else{
                if(nums[mid]<=target && nums[e]>=target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
        }
        return -1;
    }
};