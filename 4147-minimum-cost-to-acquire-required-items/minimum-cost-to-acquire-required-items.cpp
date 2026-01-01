class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // greedy approach
        long long ans = 0 ;
        if(costBoth < cost1 + cost2 ){
            ans += costBoth*1LL*min(need1,need2);
            if(need1>need2){
                long long extra = need1 - need2 ;
                if(cost1<costBoth){
                    ans += extra*1LL*cost1 ;
                }else{
                    ans += extra*1LL*costBoth ;
                }
            }else{
                long long extra = need2 - need1 ; 
                if(cost2<costBoth){
                    ans += extra*1LL*cost2;
                }else{
                    ans += extra*1LL*costBoth ;
                }
            }
        }else{
            ans += cost1*1LL*need1 ;
            ans += cost2*1LL*need2 ;
        }
        
        return ans ;
    }
};