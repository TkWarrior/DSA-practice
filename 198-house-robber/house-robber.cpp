class Solution {
public:
    int dp[101];
    int  solve(vector<int>& nums , int ind ){     
        if(ind<0) return 0 ;
        if(dp[ind]!=-1) return dp[ind];
        if(ind == 0 ) return nums[ind];
        if(ind == 1) return max(nums[ind],nums[ind-1]) ;
        
        return dp[ind] = max(nums[ind] + solve(nums,ind-2) , solve(nums , ind-1));
    }
    int rob(vector<int>& nums) {
        // maximum sum of non adjacent elements
        int n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(nums , n-1);

    }
};