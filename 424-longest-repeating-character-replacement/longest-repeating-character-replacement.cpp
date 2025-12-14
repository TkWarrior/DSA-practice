class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 ;
        int r = 0 ; 
        int n = s.size() ; 
        unordered_map<char ,int>umap ; 
        int max_freq = 0 ; 
        int max_len = 0 ;
      
        while(r<n){
            umap[s[r]]++;
            max_freq = max(max_freq , umap[s[r]]);

            if((r-l+1)-max_freq > k){
                umap[s[l]]--;
                l++ ;
            }
            max_len = max(max_len , r-l+1);
            r++;
        }

        return max_len ; 
        
    }
};