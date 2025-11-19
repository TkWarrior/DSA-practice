class Solution {
public:
    int minInsertions(string s) {
        string p = s;
        reverse(p.begin() , p.end());
        int m = p.size();

        vector<vector<int>>dp(m+1,vector<int>(m+1));

        for(int i = 0; i<m+1 ; i++){
            for(int j = 0 ; j<m+1 ; j++){
                if(i==0||j==0){
                    dp[i][j] = 0 ;
                }
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

        return m - dp[m][m];
    }
};