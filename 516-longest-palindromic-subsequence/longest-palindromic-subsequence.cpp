class Solution {
public:
    int LCS(string&s , string&p , int m ){
        vector<vector<int>>dp(m+1 , vector<int>(m+1));

        for(int i = 0 ; i<m+1 ; i++){
            for(int j = 0 ; j<m+1 ;j++){
                if(i==0 || j==0) dp[i][j] = 0 ;
            }
        }

        for(int i = 1 ; i<m+1 ; i++){
            for(int j = 1 ; j<m+1 ; j++){
                if(s[i-1]==p[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[m][m];
    }
    int longestPalindromeSubseq(string s) {
        // if we write the code of lcs dirst and then figure it out
        // store every palindromic subsequence in the dp and then return the maximum one -  first thought   
        string p = s ;
        reverse(p.begin() , p.end());
        int m = s.size() ; 
      
        return LCS(s , p, m);
       
    }
};