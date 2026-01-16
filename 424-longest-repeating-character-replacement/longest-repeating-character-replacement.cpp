class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0 ;
        int r = 0 ;
        int max_length = 0;
        unordered_map<char,int>freq;
        int max_freq = 0 ;
        int wl = 0 ; // window size 
        int max_wl = 0 ;

        while(r<n){
            freq[s[r]]++;
            max_freq = max(max_freq , freq[s[r]]);
            wl = r-l+1;
            while(wl-max_freq > k){ // keep shrinking the window until it beacame valid again
                freq[s[l]]--;
                l++;
                wl = r-l+1 ; 
            }
            if(wl-max_freq <= k){ // only for valid
                max_wl = max(wl , max_wl);
                r++;
            } 
        }

        return max_wl ;
        
    }
};