class Solution {
public:
    int dp[2001][2001];
    bool pal[2001][2001];
   void buildPalindromeTable(string &s) {
    int n = s.size();

    int g = 0;
    while (g < n) {

        int i = 0;
        int j = g;

        while (j < n) {

            if (g == 0) {
                pal[i][j] = true;                    // Single char
            } 
            else if (g == 1) {
                pal[i][j] = (s[i] == s[j]);         // Two chars
            } 
            else {
                pal[i][j] = (s[i] == s[j] && pal[i+1][j-1]);
            }

            i++;
            j++;
        }

        g++;
    }
}
    int solve(string&s , int i , int j ){
       
        if(i>=j) return 0;
        int ans  = INT_MAX ; 
        
        if(pal[i][j]) return 0 ; 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       
        for(int k = i ; k<j ; k++){
            if(pal[i][k]){
                int right = 1+solve(s , k+1 , j);
                ans = min(ans , right);
            }
      
        }

        return dp[i][j] = ans; 
    }
    int minCut(string s) {
        memset(dp , -1 , sizeof(dp)) ;   
      
        buildPalindromeTable(s) ;

        int i = 0;
        int j = s.size()-1;
        return solve(s , i , j );
    }
};