class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size() ; 
        int n = t.size() ;

        vector<vector<int>>dp(m+1 , vector<int>(n+1));

        for(int i = 0 ; i<m+1 ; i++){
            for(int j = 0 ; j<n+1 ; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0 ;
                }
            }
        }

        for(int i = 1 ; i<m+1 ; i++){
            for(int j =1 ; j<n+1 ; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }    

        if(dp[m][n] == m) return true ;

        return false;
    }
};