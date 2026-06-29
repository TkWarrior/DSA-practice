class Solution {
public:
    int dp[2501][2501];
    int lis(vector<int>&nums , int prev_ind , int ind, int n){
        if(ind>=n){
            return 0;
        }

        if(prev_ind!=-1 && dp[prev_ind][ind]!=-1){
            return dp[prev_ind][ind];
        }
        
        int take = 0 ;

        if(prev_ind==-1 || nums[prev_ind] < nums[ind]){
           take = 1 + lis(nums , ind , ind+1 , n);
        }
        int skip = lis(nums , prev_ind , ind+1 , n);

        if(prev_ind!=-1){
            return dp[prev_ind][ind] = max(take , skip);
        }
        
        return max(take , skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev_ind = -1 ;
        int ind = 0 ;
        memset(dp , -1 ,sizeof(dp));
        return lis(nums ,prev_ind , ind  , n);
    }
};