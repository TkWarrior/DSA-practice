class Solution {
public:
    int dp[2501][2501];
    int lis(vector<int>&nums , int prev , int ind , int m ){
       
        if(ind>=m){
            return 0 ; 
        }
        if(prev != -1 && dp[prev][ind]!=-1){
            return dp[prev][ind];
        }
        int take = 0 ;
        if(prev == -1 || nums[prev]<nums[ind]){
            take = 1 + lis(nums , ind , ind+1 , m);
        }
        
        int skip = lis(nums , prev , ind+1 , m);
        if(prev!=-1){
            return dp[prev][ind] = max(take , skip);
        }
        return max(take , skip);
        
    }
    int lengthOfLIS(vector<int>& nums) {
       
       int m = nums.size() ; 
       memset(dp , -1 ,sizeof(dp));
       if(m==1) return 1 ;
        int prev = -1 ;
        int ind = 0 ;
       return lis(nums , prev , ind , m);

    }
};