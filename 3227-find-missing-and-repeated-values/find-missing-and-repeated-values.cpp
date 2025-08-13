class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>umap;

        unordered_map<int , bool>umap2(false)  ;
        int n = grid.size(); 
        vector<int>missing_repeated;
        for(int i = 0  ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                    umap2[grid[i][j]] = true;
                    umap[grid[i][j]]++;
            }
        }

        
        for(auto it : umap){
            if(it.second>1){
                missing_repeated.push_back(it.first);
            }
        }

        for(int i = 1 ; i <= pow(n,2) ; i++){
                if(!umap2[i]){
                    missing_repeated.push_back(i);
                }
            }


        return missing_repeated;

    }
};