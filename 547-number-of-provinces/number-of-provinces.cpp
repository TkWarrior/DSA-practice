class Solution {
public:
    void dfs(int node , vector<vector<int>>&adjLs , vector<int>&vis){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it , adjLs , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // converting into adjacency matrix to adjacency list
        vector<vector<int>>adjLs(n);
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){

                if(isConnected[i][j]==1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int size = adjLs.size();
        // traversing adjacent list
        int node = 0 ;
        int cnt = 0 ;
        vector<int>vis(n,0);

        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i , adjLs , vis);
            }
        } 
         return cnt;
        }
      
    };
