class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre_sum(n);
        vector<int>suf_sum(n);
        pre_sum[0] = 0;
        suf_sum[n-1] = 0;

        for(int i = 1 ; i<n ; i++){
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }

        for(int i = n-2 ; i>=0 ; i--){
            suf_sum[i] = suf_sum[i+1] + nums[i+1];
        }

        int ind = 0;
        for(int i = 0 ; i<n ; i++){
            if(pre_sum[i] == suf_sum[i]){
                ind = i ;
                return ind ;
            }
        }

        return -1;
    }
};