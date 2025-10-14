class Solution {
public:
    int countSubsetSum(int sum_s1 , vector<int>&nums , int n ){
        vector<vector<int>> dp(n + 1, vector<int>(sum_s1 + 1, 0));
        
        for(int i = 0 ; i<n+1 ; i++){
            for(int j = 0 ; j<sum_s1+1 ; j++){
                if(i==0){
                    dp[i][j] = 0 ; 
                }
                if(j == 0){
                    dp[i][j] = 1 ; 
                }
            }
        }
        
        for(int i = 1 ; i<n+1 ; i++){
            for(int j = 0 ; j<sum_s1+1 ; j++){
                
                if(nums[i-1] == 0 ){
                    dp[i][j] = 2*dp[i-1][j];
                }
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
 
        return dp[n][sum_s1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum = accumulate(nums.begin() ,nums.end() , 0);
    
        int n = nums.size() ;
        int sum_s1 = (sum+target)/2 ; 
        if((sum+target)%2!=0 || target>sum_s1 || (sum+target)<0) return false;
        return countSubsetSum(sum_s1 , nums , n); 
    }
};