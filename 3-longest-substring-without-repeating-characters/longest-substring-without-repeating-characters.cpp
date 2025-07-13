class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ; 
        int r = 0 ; 
        int max_len = 0;
        int n = s.length();
        unordered_map<char,int>umap;
        int len = 1;
        while(r<n){
            
            if(umap.find(s[r])!= umap.end()){          
                if(umap[s[r]] >=l){
                    l = umap[s[r]]+1;
                }
            } 
            len = r-l+1;
            umap[s[r]] = r;
            max_len = max(max_len,len);
            r++;
        }
      
        return max_len;
    }
};