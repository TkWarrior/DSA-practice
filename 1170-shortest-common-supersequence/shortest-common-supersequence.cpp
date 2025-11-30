class Solution {
public:
     int dp[1001][1001];
    int lcs(string&str1 , string&str2 , int m , int n){
        if(m==0 || n==0) return 0 ;
        if(dp[m][n] != -1) return dp[m][n];
        if(str1[m-1]==str2[n-1]){
            return dp[m][n] = 1 + lcs(str1 , str2 , m-1 ,n-1);
        }

        return dp[m][n] = max(lcs(str1 , str2 , m-1 ,n) , lcs(str1 ,str2 ,m , n-1));
    }
    string shortestCommonSupersequence(string str1, string str2) {
         int m = str1.size() ; 
         int n = str2.size() ; 
         memset(dp , -1 , sizeof(dp));
         int LCS = lcs(str1 , str2 , m , n );
         int i = m ;
         int j = n ;
         string res = "" ;

         while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]) {
                res.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    res.push_back(str1[i-1]);
                    i--;
                }else{
                    res.push_back(str2[j-1]);
                    j--;
                }
            }
         }

         while(i>0){
            res.push_back(str1[i-1]);
            i-- ; 
         }

         while(j>0){
            res.push_back(str2[j-1]);
            j--;
         }

         reverse(res.begin() ,res.end());

         return res ; 
    }
};