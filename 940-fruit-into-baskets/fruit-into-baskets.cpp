class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0 ; 
        int r = 0 ; 
        unordered_map<int,int>umap;
        int max_len = 0 ;
        int n = fruits.size();
        while(r<n){
            umap[fruits[r]]++;
           
                while(umap.size()>2){
                    umap[fruits[l]]--;
                    if(umap[fruits[l]]==0){
                        umap.erase(fruits[l]);            
                    }
                  l++;
                }
       
        
                max_len = max(max_len , r-l+1);
              
           
            r++;
           
        }
        return max_len;
    }
};