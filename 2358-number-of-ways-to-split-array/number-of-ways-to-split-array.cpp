class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n);
        vector<long long>suffix(n);
        int c = 0 ;
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1 ; i<n ; i++){
            prefix[i] = prefix[i-1]+nums[i];
        }

        for(int j = n-2 ; j>=0 ; j--){
            suffix[j] = suffix[j+1]+nums[j];
        }

        for(int k = 0 ; k<n-1 ; k++){
            if(prefix[k]>=suffix[k+1]){
                c++;
            }
        }

        return c  ;
    }
};