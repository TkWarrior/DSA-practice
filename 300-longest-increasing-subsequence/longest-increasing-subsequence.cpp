class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>& nums , int prev_ind , int curr_ind , int n){
        if(curr_ind==n){
            return 0;
        }

        if(prev_ind!=-1 && dp[prev_ind][curr_ind]!=-1){
            return dp[prev_ind][curr_ind];
        }

        int take = 0 ;

        if(prev_ind==-1 || nums[curr_ind]>nums[prev_ind]){
            take =  1 + solve(nums , curr_ind , curr_ind+1 , n);
        }

        int skip = solve(nums , prev_ind , curr_ind+1 , n);

        if(prev_ind!=-1){
            return dp[prev_ind][curr_ind] = max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
       
        int n = nums.size();
        int curr_ind = 0 ;
        int prev_ind = -1;
        memset(dp,-1,sizeof(dp));
        return solve(nums , prev_ind , curr_ind , n);
        
    }
};