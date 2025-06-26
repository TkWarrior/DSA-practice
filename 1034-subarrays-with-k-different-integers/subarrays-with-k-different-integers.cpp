class Solution {
public:

    int countSubarrayWithDistinct(vector<int>& nums, int k){
        int count = 0 ; 
        int n = nums.size();
        unordered_map<int,int>hashmap;
        int l = 0 , r = 0;
        
        while(r<n){
            hashmap[nums[r]]++;
            while(hashmap.size()>k){
                hashmap[nums[l]]--;
                if(hashmap[nums[l]]==0){
                    hashmap.erase(nums[l]);
                }
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // subarray formed with less than or equal to k different integer - subarray formed with less than or equal to k-1 different integer

        int count = countSubarrayWithDistinct(nums,k) - countSubarrayWithDistinct(nums,k-1);
        return count;
        
    }
};