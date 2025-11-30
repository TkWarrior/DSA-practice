class Solution {
public:
    int dp[501][501];
    int minOp(string&word1 , string&word2 , int m , int n){
        if(m==0){
            return n;
        }
         if(n==0){
            return m;
        }

        if(dp[m][n]!=-1) return dp[m][n];
       
        if(word1[m-1]==word2[n-1]){
            return dp[m][n] = minOp(word1 , word2 , m-1 ,n-1);
        }
        //minimum between insert delete and insert
        int min1 = min(1+minOp(word1 , word2 ,m , n-1) , 1+minOp(word1 ,word2 ,m-1 ,n));

        // minimum betweern replace , insert and delete
        return dp[m][n] = min(min1 , 1+minOp(word1 , word2 ,m-1 , n-1));
    }
    int minDistance(string word1, string word2) {
        int m = word1.size() ; 
        int n = word2.size() ; 
        memset(dp , -1 , sizeof(dp));
        return  minOp(word1 , word2 , m , n ); 

    }
};