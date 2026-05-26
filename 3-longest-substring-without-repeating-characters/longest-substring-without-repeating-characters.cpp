class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int ,int>umap ;
        int l = 0 ;
        int r = 0 ;
        int max_ws = 0;
        int ws = 0;
        int n = s.size(); 

        while(r<n){
            if(umap.find(s[r])!=umap.end()){
                if(umap[s[r]]>=l){
                    l = umap[s[r]]+1;
                }
            }
            ws = r-l+1 ;
            max_ws = max(max_ws ,ws);
            umap[s[r]] = r ;
            r++;
        }

        return max_ws;
    }
};