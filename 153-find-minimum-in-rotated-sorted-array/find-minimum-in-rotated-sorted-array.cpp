class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int n = nums.size();
        int s = 0 ;
        int e = n-1;
        int mid;

        if(nums[0]<nums[e]){
            return nums[0];
        }
        
        while(s<e){
            mid = s + (e-s)/2;
            if(nums[mid]>nums[e]){
                s = mid+1;
            }else{
                e = mid;
            }
            
        }

        return nums[e];
    }
};