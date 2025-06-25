class Solution {
public:
    int countOfSubarraylessThan(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int count = 0;
    
        if(k<0){
            return 0; 
        }
        // in this approach we will convert the odd number to 1 and event number to 0
        while(r<n){
            sum = sum + (nums[r]%2);
            while(sum>k){
                sum = sum - (nums[l]%2);
                l++;
            }
            count = count+(r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Brute force sol 
        // int count= 0 ;
        // int count_k_odd_subarray = 0;
        // int n = nums.size();
        // for(int i = 0 ; i<n ; i++){
        //     count = 0;
        //     for(int j = i ; j<n ; j++){
        //         if(nums[j]%2!=0){
        //             count++;
        //         }
        //         if(count==k){
        //             count_k_odd_subarray++;
        //         }
        //         if(count>k){
        //             break;
        //         }
        //     }
        // }
        // return count_k_odd_subarray;

        //Optimal Soln 
        // no of subarrays equal to k  = no of subarray less than or equal to k + no of subarray less than or equal to  k-1
        //it is just the twist of the previous question 
        return countOfSubarraylessThan(nums,k) - countOfSubarraylessThan(nums,k-1);
    }
};