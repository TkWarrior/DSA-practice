class Solution {
public:
    int dp[501][501];
    int lcs(string&word1 , string&word2 , int m , int n){
        if(m==0 || n==0) return 0;
        if(dp[m][n] != -1) return dp[m][n] ;
        if(word1[m-1]==word2[n-1]) return dp[m][n] =  1 + lcs(word1 , word2 , m-1 ,n-1);

        return dp[m][n] = max(lcs(word1 , word2 , m-1 , n) ,lcs(word1 , word2 , m , n-1));
    }
    int minDistance(string word1, string word2) {
        // length of lcs is the ans here
        int  m = word1.size();
        int n = word2.size();
        memset(dp , -1 ,sizeof(dp));
        int LCS = lcs(word1 , word2 , m , n);

        return m+n - 2*LCS ;


    }
};