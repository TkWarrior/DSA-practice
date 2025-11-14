class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { 
        int n = coins.size();
      vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1));
      
      
      // initializing 0th row and 0th coloumn
       for(int i = 0 ; i<n+1 ; i++){
            for(int j = 0 ; j<amount+1 ; j++){
                if(j==0){
                    dp[i][j] = 0 ;
                }
                if(i==0){ // initialize first row with INT_MAX - 1
                    dp[i][j] = INT_MAX - 1; 
                }
                
            }
       }
    
       // initializing 1st row and 1st coloumn
       
       for(int j=1;j<amount+1 ; j++){

            if(j%coins[0]==0){
                dp[1][j] = j/coins[0];
            }else{
                dp[1][j] = INT_MAX-1 ; 
            }
       }

        // in
       for(int i = 2 ; i<n+1 ; i++){
            for(int j = 1 ; j<amount+1 ; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
       }

     
       if(dp[n][amount] == INT_MAX-1) return -1 ; 
   

       return dp[n][amount];
    }
};