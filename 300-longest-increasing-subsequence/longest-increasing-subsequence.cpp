class Solution {
public:
    int dp[2501][2501];
   
    int lis(vector<int>& nums , int ind ,int prev_ind , int n){   
      
        if(ind>=n){
            return 0 ;
        }
        int take = 0 ;
        if(prev_ind !=-1 && dp[ind][prev_ind]!=-1) return dp[ind][prev_ind];
        if(prev_ind == -1 || nums[prev_ind]<nums[ind]){
            take = 1 + lis(nums , ind+1 ,ind ,n);
        }
        
       
        int skip = lis(nums , ind+1 ,prev_ind ,n);
        
        if(prev_ind != -1){
            dp[ind][prev_ind] = max(take ,skip);
        }
        return max(take , skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        // 0 0 1 2 3 3
        // 0 1 0 3 2 3
        // 0 1 2 3
        int n = nums.size() ; 
        memset(dp,-1,sizeof(dp));
        return lis(nums ,0 , -1 ,n);

    }
};