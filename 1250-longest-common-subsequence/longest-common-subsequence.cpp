class Solution {
public:
    int dp[1002][1002];
    int LCS(string&text1, string&text2 , int  m , int n ){
        
        if(m==0 || n==0) return 0 ; 

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        if(text1[m-1]==text2[n-1]) {
            return dp[m][n] = 1 + LCS(text1 , text2 , m-1 ,n-1);
        }

        return dp[m][n] = max(LCS(text1 , text2 , m ,n-1) , LCS(text1 , text2 , m-1,n));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() ; 
        int n = text2.size() ; 
        memset(dp,-1 ,sizeof(dp));
        return LCS(text1 , text2 , m , n);
    }
};