class Solution {
public:
 // little bit of knapsack type
 // whenever we want to to find the no of ways in top down approach fill the 0th row with 0's and 0th column with 1's
    int dp[1001][1001];
    int solve(string&s , string&t , int m , int n){
        if(n<0){
            return 1;
        }
        if(m<0){
            return 0 ;
        }
        if(dp[m][n]!=-1){
            return dp[m][n] ; 
        }
        // if(m==0){
        //     return 1 ;
        // }
        if(s[m]==t[n]){
            return dp[m][n] = solve(s,t,m-1,n-1)+solve(s,t,m-1,n);
        }

        return dp[m][n] = solve(s,t,m-1,n);
    }
    int numDistinct(string s, string t) {
        int m = s.size() ; 
        int n = t.size() ;
        memset(dp , -1 , sizeof(dp));
        // vector<vector<unsigned long long>>dp(m+1 , vector<unsigned long long>(n+1));

        // for(int i = 0 ; i<m+1 ; i++){
        //     for(int j = 0 ; j<n+1 ; j++){
        //         if(i==0){
        //             dp[i][j] = 0;
        //         }
        //         if(j==0){
        //             dp[i][j] = 1 ;
        //         }
        //     }
        // }
        
        // for(int i = 1 ; i<m+1 ; i++){
        //     for(int j = 1 ; j<n+1 ; j++){
        //         //choice diagram
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //         }else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }        
        // }

        return solve(s, t , m-1 , n-1 );
    }
};