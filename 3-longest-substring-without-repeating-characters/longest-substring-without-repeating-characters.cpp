class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0 ;
       int r = 0 ;
       int n = s.size();
       unordered_map<char , int>mp;
       int ws = 0;
       int max_ws = 0 ;

       while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l){
                     l = mp[s[r]]+1;
                } 
            }
            ws = r-l+1;
            max_ws = max(ws , max_ws);
            mp[s[r]] = r ;
            r++;
       }

       return max_ws;
    }
};