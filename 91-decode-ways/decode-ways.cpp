class Solution {
public:
    int dp[101];
    int solve(string&s , int i , int&n){
        if(i==n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        int result = solve(s , i+1 ,n);

        if(i+1<n){
            if(s[i]=='1' && s[i+1]<='9' || s[i]=='2' && s[i+1]<='6'){
                result += solve(s ,i+2 , n);
            }
        }
        
        return dp[i] = result;
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s , 0 , n);
    }
};