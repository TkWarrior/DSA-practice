class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0 ;
        int maxi = INT_MIN ; 
        int n = s.size();
        unordered_map<char,int>umap ;
        int l = 0 ; 
        int r = 0 ; 
        if(n==0){
            return 0 ; 
        }
        while(r<n){
            if(umap.find(s[r])!=umap.end()){
                if(umap[s[r]]>=l){
                    l = umap[s[r]] + 1;
                }
            }
            count = r-l+1;
            maxi = max(maxi , count);
            umap[s[r]] = r ; 
            r++;
        }
       
        return maxi  ;
    }
};