class Solution {
public:

    string LCS(string&str1, string&str2,int m , int n ){
        // vector<vector<int>>dp(m+1 , vector<int>(n+1));
        vector<vector<int>>dp(m+1,vector<int>(n+1)); 
        string s = "";
        for(int i = 0 ; i<m+1 ; i++){
            for(int j = 0 ; j<n+1 ; j++){
                if(i==0 || j==0){
                    dp[i][j] = 0 ;
                }
            }
        }

        for(int i = 1 ; i<m+1 ; i++){
            for(int j = 1 ; j<n+1 ; j++){
                if(str1[i-1]==str2[j-1]){
                  
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

       
        int i = m , j = n ; 

        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s.push_back(str1[i-1]);// store the common character
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    s.push_back(str1[i-1]); // store the maximum character
                    i--;
                }else{
                    s.push_back(str2[j-1]); // store the maximum character
                    j--; 
                }
            }  
        }

        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }

        while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        return s ; 

    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length() ; 
        string s = LCS(str1 , str2 , m , n );
        reverse(s.begin() , s.end());
        return s;  
    }
};