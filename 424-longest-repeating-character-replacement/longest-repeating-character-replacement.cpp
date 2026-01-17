class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 ;
        int r = 0 ;
        unordered_map<char,int>mp;
        int n = s.size();
        int max_freq = 1 ;
        int longest = 1 ;

        while(r<n){
            mp[s[r]]++;
            int window_size = r-l+1;
            max_freq = max(max_freq , mp[s[r]]);
            if((window_size - max_freq)>k){
                mp[s[l]]--;
                l++;
                window_size = r-l+1 ;
            }
            longest = max(longest , window_size);
            r++;
        }
        
        return longest ; 

    }
};