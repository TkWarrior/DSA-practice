class Solution {
public:
   
    int searchInsert(vector<int>& nums, int target) {
        int s = 0 ;
        int e = nums.size()-1;
        int mid = (s+e)/2;
        while(s<=e){
            if(nums[mid]<target){
                s = mid+1;
            }
            else if(nums[mid]>target){
                e = mid - 1;
            }
            else{
                return mid;
            }
            mid = (s+e)/2;
        }
        return s;
    }
};