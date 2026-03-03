class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int s = 0 ;
        int e = n-1;
        int mid;

        while(s<=e){
            mid = s + (e-s)/2;
            
            if(nums[mid]==target){
                return mid;
            }

            if(nums[mid]>=nums[s]){ // left half sorted
                if(nums[s]<=target && target<nums[mid]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }else{ // right half sorted
                if(nums[mid]<target && target<=nums[e]){
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
        }

        return -1;
        
    }
};