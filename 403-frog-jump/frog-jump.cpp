class Solution {
public:
    int dp[2001][2001];
    unordered_map<int,int>umap;
    bool f(vector<int>& stones , int cs_i , int pj , int n ){
        if(cs_i == n-1 ) return true ; 

        if(dp[cs_i][pj]!=-1) return dp[cs_i][pj];

        bool reach = false ;
        for(int next_j=pj-1 ; next_j <= pj+1;next_j++){
            if(next_j > 0){
                int next_stone = stones[cs_i]+next_j ;
                if(umap.find(next_stone)!=umap.end()){
                    reach =  reach || f(stones , umap[next_stone] , next_j ,n );
                }
            }
        }
        return dp[cs_i][pj] = reach ;
    }
    bool canCross(vector<int>& stones) {
       if(stones[1]-stones[0]!=1) return false ; 
       int n = stones.size() ;
       memset(dp , -1 , sizeof(dp));
       
        for(int i = 0 ; i < n ; i++){
            umap[stones[i]] = i ; 
        }
       return f(stones , umap[0] , 0 , n );
    }
};