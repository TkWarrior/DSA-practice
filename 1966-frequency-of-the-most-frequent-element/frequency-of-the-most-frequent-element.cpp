class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long max_freq = 0 ; 
        sort(nums.begin(),nums.end());
        long long r = 0 ; 
        long long  l = 0 ;
        long long  cost = 0 ; 
        long long n = nums.size();
        long long sum = 0;
        while(r<n){
            sum += nums[r];
            cost = (r-l+1)*nums[r] - sum ; 

            while(cost>k){
                sum -= nums[l];
                l++;           
                cost = (r-l+1)*nums[r] - sum;
            }
            max_freq = max(max_freq , r-l+1);
            r++;
        }

        return max_freq;
    }
};