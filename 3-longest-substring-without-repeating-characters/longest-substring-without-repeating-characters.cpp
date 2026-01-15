class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0 ; 
        int r = 0 ; 
        int max_length = 0 ;
        unordered_map<int,int>mp ;

        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                    l = mp[s[r]] + 1;
                }    
            }
            max_length = max(max_length , r-l+1);
            mp[s[r]] = r ;
            r++ ;
        }
        
        return max_length ;
    }
};