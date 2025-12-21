class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // odd length array will always contain one single element 
        // pair of duplicate elements will be of even and odd indices

        int n = nums.size() ;
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-2]!=nums[n-1]){
            return nums[n-1];
        }

        int s = 0 ;
        int e = n-1 ; 
        int mid;
        while(s<=e){
            mid = (s+e)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]){
                break ;
            }
            else if(mid%2==0 && nums[mid+1] == nums[mid] || mid%2 == 1 && nums[mid-1]==nums[mid]){
                s = mid+1;
            }else{
                e = mid - 1 ; 
            }
        }

        return nums[mid];
    }
};