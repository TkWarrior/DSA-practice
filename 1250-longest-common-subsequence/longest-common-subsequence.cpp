class Solution {
public:
    int dp[1001][1001];
    int lcs(int m , int n , string&text1 , string&text2){
        if(m==0 || n==0) return 0 ;

        if(dp[m][n] != -1) return dp[m][n];

        if(text1[m-1]==text2[n-1]){
            return dp[m][n] = 1 + lcs(m-1 , n-1 , text1 , text2);
        }

        return dp[m][n] = max(lcs(m-1 ,n , text1 , text2), lcs(m , n-1 , text1 , text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
       int m = text1.size() ; 
       int n = text2.size() ; 
        memset(dp,-1 , sizeof(dp));
       return lcs(m , n , text1 , text2);
    }
};