class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ;
        int max_profit = 0 ;
        int n = prices.size();

        int l = 0 ;
        int r = 1 ; 
         
        while(r<n){
            if(prices[r]<prices[l]){
                l++;
            }else{
                profit = prices[r]-prices[l];
                max_profit = max(max_profit ,profit);
                r++;
            }
        }

        return max_profit ;
    }
};