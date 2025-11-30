class Solution {
public:
    int dp[1001][1001];
    int lcs(string&s ,string&t , int m , int n  ){
      
        if(m==0 || n==0) return 0 ;

        if(dp[m][n] != -1) return dp[m][n];

        if(s[m-1] == t[n-1]){
            return dp[m][n] = 1 + lcs(s , t ,m-1 , n-1);
        }

        return dp[m][n] = max(lcs(s , t ,m-1 , n) , lcs(s,t , m , n-1));

    }
    int longestPalindromeSubseq(string s) {
        int n =  s.size() ;
        memset(dp , -1 ,sizeof(dp));
        string t = s ; 
        reverse(t.begin() , t.end());
        int m = t.size() ;
        return lcs(s, t , m , n);
    }
       
};