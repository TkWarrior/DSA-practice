class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0 ; 
        int e = n-1;
       
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                return true ; 
            }
            if(nums[s]==nums[mid] && nums[mid] == nums[e]){
                s++;
                e--;
                continue;
            }
            if(nums[s]<=nums[mid]){
                if(nums[s]<=target && nums[mid]>=target){
                    e = mid - 1;
                }else{
                    s = mid + 1 ;
                }
            }else{
                if(nums[mid]<=target && nums[e]>=target){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
           
        }
        return false;
    }
};