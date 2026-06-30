class Solution {
public:
    int dp[2501][2501];
    int lcs(vector<int>& nums ,int prev_ind , int ind , int n){
        if(ind==n){
            return 0;
        }
        int take = 0 ;
        if(prev_ind!=-1 && dp[prev_ind][ind]!=-1){
            return dp[prev_ind][ind];
        }
        if(prev_ind==-1 || nums[prev_ind]<nums[ind]){
            take = 1 + lcs(nums , ind , ind+1 , n);
        }
        int skip = lcs(nums,prev_ind , ind+1 , n);
        if(prev_ind!=-1){
            return dp[prev_ind][ind] = max(take , skip);
        }
        return max(take , skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ind = 0 ;
        int prev_ind = -1;
        memset(dp , -1 ,sizeof(dp));
        return lcs(nums ,prev_ind , ind , n);
    }
};