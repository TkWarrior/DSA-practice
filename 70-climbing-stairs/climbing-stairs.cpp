class Solution {
public:
    int dp[1001][1001];
    
    int solve(int n ){
        if(n==0 || n==1){
            return dp[n][n] = 1;
        }
        if(dp[n][n] != -1){
            return dp[n][n];
        } 

        return dp[n][n] = solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        memset(dp , -1 , sizeof(dp));
        return solve(n);
    }
};