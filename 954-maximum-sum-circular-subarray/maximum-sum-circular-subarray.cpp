class Solution {
public:

    int kadanesMax(vector<int>& nums , int n){
        int max_sum = INT_MIN;
        int sum = 0;

        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
            max_sum = max(max_sum , sum);
            if(sum<0) {
                sum = 0;
            }
        }
    
        return max_sum;
    }

    // To calculate minimum subarray sum
    int kadanesMin(vector<int>& nums, int n){
        int min_sum = INT_MAX;
        int sum = 0;

        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
            min_sum = min(min_sum , sum);
            if(sum>0) {
                sum = 0;
            }
        }
    
        return min_sum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        // Opotimal Soln - using kadane's algorithm 
        // first calculate the sum of the array
        int n  = nums.size();
        int sum = 0 ; 
        
        for (int i = 0 ; i < n ; i++){
            sum += nums[i];
        }

        int min_subarray_sum = kadanesMin(nums, n);

        int max_subarray_sum = kadanesMax(nums, n);

        int circular_subarray_sum = sum - min_subarray_sum;

        if(max_subarray_sum < 0 ){
            return max_subarray_sum;
        }

        return max(max_subarray_sum, circular_subarray_sum);
    }
};