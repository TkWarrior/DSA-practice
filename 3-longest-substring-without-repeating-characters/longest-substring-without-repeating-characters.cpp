class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char , int>hashmap;
       int n = s.size();
       int l = 0 ;
       int r = 0 ;
       int ws = 0 ;
       int max_ws = 0 ;

       while(r<n){
           
            if(hashmap.find(s[r])!=hashmap.end()){
                if(hashmap[s[r]]>=l){
                    l =  hashmap[s[r]] + 1;
                }
            } 
            ws = r-l+1;  
            max_ws = max(max_ws , ws);
            hashmap[s[r]] = r;
            r++;
       }

       return max_ws;
    }
};