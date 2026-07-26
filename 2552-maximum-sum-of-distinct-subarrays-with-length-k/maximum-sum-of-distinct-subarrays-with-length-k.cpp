class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n = nums.size();
        int i = 0 , j = 0 ;
        long long s = 0;
        long long max_s = 0 ;

        while(j<n){
            
            while(st.find(nums[j])!=st.end()){
                st.erase(nums[i]);
                s -= nums[i];
                i++;
            }
            s += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                max_s = max(s , max_s);
                s -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        return max_s;
    }
};